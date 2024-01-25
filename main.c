 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include <stdint.h>
#include <stdbool.h>

#include <string.h>
#include <xc.h>
#include "mcc_generated_files/system/system.h"
#include "common.h"
#include "bme280.h"
#include <math.h>
#include <stdio.h>



/**
 * To get this program to work you have to:
 * 
 * 1. Set the "Reset Oscillator Selection bits" to HFINTOSC (32MHz) in the 
 *    Configuration Bits section of MCC. 
 * 2. Set the "Current Oscillator Souce Select" to "HFINTOSC_32MHz" in Clock Control
 * 3. Set the "HF Internal Clock" to "32_MHz" in Clock Control
 * 4. Increase the power supply voltage to 5.5 in PK0B Nano -> Power section 
 *    of the project properties.
 * 
 * These config changes make it so that the board can power the DHT11 with 
 * sufficient voltage and ensure the MCU is fast enough to recognize the DHT11
 * input pulses. 
 * 
 * This code requires a bit more work to ensure it doesn't get stuck in an 
 * infinite loop. 
 * 
 * @return 
 */
#define BME280_I2C_ADDRESS  0xEC
#define SAMPLE_COUNT  UINT8_C(50)
uint8_t data[26] = { 0 };




void setup_lora();
void setup_bme280();
struct bme280_dev get_bme280();
struct bme280_data get_temperature(struct bme280_dev *dev);
bool is_measurement_done(struct bme280_dev *dev);
void write_lora(char data[]);
void read_lora();
void send(uint8_t address, char tag[], double metric);

void setup_lora() {
    
    IO_RC7_SetDigitalInput();
    IO_RC6_SetDigitalOutput();
    
    EUSART1_Enable();
    EUSART1_TransmitEnable();
    EUSART1_ReceiveEnable();
}

void setup_bme280() {
    
    IO_RB1_SetDigitalMode();
    IO_RB1_SetPullup();
    IO_RB2_SetDigitalMode();
    IO_RB2_SetPullup();
}

struct bme280_dev get_bme280() { 
    
    int8_t rslt;
    struct bme280_dev dev;
    struct bme280_settings settings;
    
    rslt = bme280_interface_selection(&dev, BME280_I2C_INTF);
    rslt = bme280_init(&dev);
    rslt = bme280_get_sensor_settings(&settings, &dev);

    /* Configuring the over-sampling rate, filter coefficient and standby time */
    /* Overwrite the desired settings */
    settings.filter = BME280_FILTER_COEFF_OFF;

    /* Over-sampling rate for humidity, temperature and pressure */
    settings.osr_h = BME280_OVERSAMPLING_1X;
    settings.osr_p = BME280_OVERSAMPLING_1X;
    settings.osr_t = BME280_OVERSAMPLING_1X;

    /* Setting the standby time */
    settings.standby_time = BME280_STANDBY_TIME_0_5_MS;

    rslt = bme280_set_sensor_settings(BME280_SEL_ALL_SETTINGS, &settings, &dev);
    rslt = bme280_set_sensor_mode(BME280_POWERMODE_SLEEP, &dev);
    
    return dev;
}

void send(uint8_t address, char tag[], double metric) {
    
    // Limit the size of the tag to 20 characters
    if(sizeof(tag) > 20) {
        // TODO: Return error
    }
    
    // There shouldn't be more than 10 characters in the metric, including
    // decimals and negative signs.
    char t[10];
    float rounded = roundf(metric * 100) / 100;
    sprintf(t, "%g", rounded);
    
    // Calculate the payload size, since any null values won't be written
    // to the final buffer.
    int payload_size = snprintf(NULL, 0, "%s::%s", tag, t);
    printf(payload_size);
    
    // The final result to send should not be greater than 50 characters
    char buffer[50] = {0};
    sprintf(buffer, "AT+SEND=%i,%i,%s::%s\r\n", address, payload_size, tag, t);
    printf(buffer);
    
    write_lora(&buffer);
    read_lora();
}

void write_lora(char *data) {
    
    bool carriage_found = false;
    bool newline_found = false;
    
    uint8_t size = sizeof(data);
    printf(size);
    for(uint8_t i = 0; i < 50; i++) {
        
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

void read_lora() {
    
    //TODO: Add a timer here so this doesn't perpetually poll
    while(!EUSART1_IsRxReady());
    
    bool carriage_found = false;
    bool newline_found = false;
    
    char data[50] = {0};
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

int main(void){
    
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    setup_lora();
    setup_bme280();
    
    struct bme280_dev dev = get_bme280();
    struct bme280_data weather = get_temperature(&dev);

    while(1) {
        struct bme280_data weather = get_temperature(&dev);

        send(32, "TEMPERATURE", weather.temperature);
        __delay_ms(1000);

        send(32, "HUMIDITY", weather.humidity);
        __delay_ms(1000);

        send(32, "PRESSURE", weather.pressure);
        __delay_ms(1000);
        
        
        for(uint8_t i = 0; i < 15; i++) {
            __delay_ms(2000);
        }
        
        
    }    
}

/*!
 *  @brief This internal API is used to get compensated temperature data.
 */
struct bme280_data get_temperature(struct bme280_dev *dev)
{
    int8_t rslt = BME280_E_NULL_PTR;
    struct bme280_data comp_data;
    
    // Force a reading and wait a second for the measurement
    rslt = bme280_set_sensor_mode(BME280_POWERMODE_NORMAL, dev);
    printf(rslt);
    __delay_ms(1000);
    
    // Wait while the device is still measuring
    while(!is_measurement_done(dev)) {
        __delay_ms(100);
    }
    
    // Get the results
    rslt = bme280_get_sensor_data(BME280_ALL, &comp_data, dev);
    return comp_data;
}


bool is_measurement_done(struct bme280_dev *dev) {
    uint8_t status_reg;
    int8_t rslt = bme280_get_regs(BME280_REG_STATUS, &status_reg, 1, dev);
    return !(status_reg & BME280_STATUS_MEAS_DONE);
}