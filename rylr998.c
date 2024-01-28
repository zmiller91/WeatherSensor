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

void rylr998_init() {
    
    // Set the TX and RX pins and input and output
    UART_RX_SetDigitalInput();
    UART_TX_SetDigitalOutput();
    
    EUSART1_Enable();
    EUSART1_TransmitEnable();
    EUSART1_ReceiveEnable();
}

void rylr998_send(uint8_t address, char serial[], char tag[], double metric) {
    
    // Limit the size of the tag to 20 characters
    if(sizeof(tag) > 20) {
        // TODO: Return error
    }
    
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
    printf(buffer);
    
    rylr998_write(&buffer);
    rylr998_read();
}

void rylr998_write(char *data) {
    
    bool carriage_found = false;
    bool newline_found = false;
    
    uint8_t size = sizeof(data);
    printf(size);
    for(uint8_t i = 0; i < 60; i++) {
        
        char c = data[i];
        EUSART1_Write(c);
        while(!EUSART1_IsTxDone());
        
        carriage_found = carriage_found || (data[i] == '\r');
        newline_found = newline_found || (data[i] == '\n');
        if(carriage_found && newline_found) {
            break;
        }
    }
    
    if(!carriage_found || !newline_found) {
        //TODO: return error, terminal characters not found
    }
}

void rylr998_read() {
    
    //TODO: Add a timer here so this doesn't perpetually poll
    while(!EUSART1_IsRxReady());
    
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
        
        //TODO: Add a timer here so it doesn't perpetually poll
        while(!EUSART1_IsRxReady());
        
    }
    
    bool success = strcmp("+OK", data) == 0;
    printf(success);
    
}