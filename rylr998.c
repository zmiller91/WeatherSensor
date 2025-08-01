/*
 * File:   rylr998.c
 * Author: zmiller
 *
 * Created on January 24, 2024, 9:10 PM
 */


#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include <xc.h>
#include "mcc_generated_files/system/system.h"

#include "rylr998.h"
#include "timeout.h"

void rylr998_init(void) {
    
    // Set the TX and RX pins and input and output
    UART_RX_SetDigitalInput();
    UART_TX_SetDigitalOutput();
    
    EUSART1_Enable();
    EUSART1_TransmitEnable();
    EUSART1_ReceiveEnable();
    timeout_init();
}

int8_t rylr998_send(uint8_t address, char serial[], char tag[], double metric) {
    
    // There shouldn't be more than 10 characters in the metric, including
    // decimals and negative signs.
    char data[10];
    float rounded = roundf(metric * 100) / 100;
    sprintf(data, "%g", rounded);
    
    // Calculate the payload size, since any null values won't be written
    // to the final buffer.
    int payload_size = snprintf(NULL, 0, "%s::%s::%s", serial, tag, data);
    char buffer[60] = {0};
    sprintf(buffer, "AT+SEND=%i,%i,%s::%s::%s\r\n", address, payload_size, serial, tag, data);
    
    int8_t response_code = rylr998_write(buffer);
    if(response_code < 0) {
        return response_code;
    }
    
    return rylr998_read();
}

int8_t rylr998_send_flat(uint8_t address, char serial[], double metrics[], uint8_t size) {
    
    char metricResult[60] = {0};
    for(uint8_t idx = 0; idx < size; idx++) {
        // There shouldn't be more than 10 characters in the metric, including
        // decimals and negative signs.
        char data[10];
        float rounded = roundf(metrics[idx] * 100) / 100;
        sprintf(data, "%g", rounded);
        
        char metricBuffer[60] = {0};
        sprintf(metricResult, "%s::%s", metricResult, data);
    }
       
    // Calculate the payload size, since any null values won't be written
    // to the final buffer.
    int payload_size = snprintf(NULL, 0, "%s%s", serial, metricResult);
    char buffer[60] = {0};
    sprintf(buffer, "AT+SEND=%i,%i,%s%s\r\n", address, payload_size, serial, metricResult);
    printf(buffer);
    int8_t response_code = rylr998_write(buffer);
    if(response_code < 0) {
        return response_code;
    }
    
    return rylr998_read();
}

bool rylr998_tx_busy(void) {
    return !EUSART1_IsTxDone();
}

int8_t rylr998_write(char *data) {
    
    bool carriage_found = false;
    bool newline_found = false;
    
    uint8_t size = sizeof(data);
    for(uint8_t i = 0; i < 60; i++) {
        
        char c = data[i];
        EUSART1_Write(c);
        
        if(!timeout_wait(rylr998_tx_busy)) {
            return RYLR998_TIMEOUT;
        }
        
        carriage_found = carriage_found || (data[i] == '\r');
        newline_found = newline_found || (data[i] == '\n');
        if(carriage_found && newline_found) {
            break;
        }
    }
    
    if(!carriage_found || !newline_found) {
        return RYLR998_INVALID_DATA;
    }
    
    return RYLR998_OK;
}

bool rylr998_rx_busy(void) {
    return !EUSART1_IsRxReady();
}

int8_t rylr998_read(void) {
    
    if(!timeout_wait(rylr998_rx_busy)) {
        return RYLR998_TIMEOUT;
    }
    
    bool carriage_found = false;
    bool newline_found = false;
    
    char data[60] = {0};
    for(uint8_t i = 0; i < sizeof(data); i++) {
        
        uint8_t byte = EUSART1_Read();
        carriage_found = carriage_found || (byte == '\r');
        newline_found = newline_found || (byte == '\n');
        
        if(!(byte == '\r' || byte == '\n')) {
            data[i] = byte;
        }
        
        if(carriage_found && newline_found) {
            break;
        }
        
        if(!timeout_wait(rylr998_rx_busy)) {
            return RYLR998_TIMEOUT;
        }
        
    }
    
    bool success = strcmp("+OK", data) == 0;
    if(success) {
        return RYLR998_OK;
    }
    
    // TODO: return more appropriate error code
    return RYLR998_UNLISTED_FAILURE;
}