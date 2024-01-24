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
static int8_t get_temperature(uint32_t period, struct bme280_dev *dev);

int main(void){
    SYSTEM_Initialize();
    
    IO_RB1_SetDigitalMode();
    IO_RB1_SetPullup();
    IO_RB2_SetDigitalMode();
    IO_RB2_SetPullup();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    __delay_ms(1000);
    
    uint8_t address = UINT8_C(0x76);
    uint8_t chipId = UINT8_C(0xD0);
    
    
    int8_t rslt;
    uint32_t period;
    struct bme280_dev dev;
    struct bme280_settings settings;
    
    rslt = bme280_interface_selection(&dev, BME280_I2C_INTF);
    rslt = bme280_init(&dev);
    rslt = bme280_get_sensor_settings(&settings, &dev);

    /* Configuring the over-sampling rate, filter coefficient and standby time */
    /* Overwrite the desired settings */
    settings.filter = BME280_FILTER_COEFF_2;

    /* Over-sampling rate for humidity, temperature and pressure */
    settings.osr_h = BME280_OVERSAMPLING_1X;
    settings.osr_p = BME280_OVERSAMPLING_1X;
    settings.osr_t = BME280_OVERSAMPLING_1X;

    /* Setting the standby time */
    settings.standby_time = BME280_STANDBY_TIME_0_5_MS;

    rslt = bme280_set_sensor_settings(BME280_SEL_ALL_SETTINGS, &settings, &dev);
    rslt = bme280_set_sensor_mode(BME280_POWERMODE_NORMAL, &dev);
    
    
    uint8_t sensor_mode;
    bme280_get_sensor_mode(&sensor_mode, &dev);
    printf(sensor_mode);
    
    rslt = bme280_cal_meas_delay(&period, &settings);
    
    
    
//    uint8_t readData;
//    I2C2_WriteRead(address, &chipId, 1, &readData, 1);
//    while(I2C2_IsBusy());
//    printf(readData);
    
    rslt = get_temperature(period, &dev);
    while(1) {
        printf(rslt);
    }    
}

/*!
 *  @brief This internal API is used to get compensated temperature data.
 */
static int8_t get_temperature(uint32_t period, struct bme280_dev *dev)
{
    int8_t rslt = BME280_E_NULL_PTR;
    int8_t idx = 0;
    uint8_t status_reg;
    struct bme280_data comp_data;

    while (idx < SAMPLE_COUNT)
    {
        rslt = bme280_get_regs(BME280_REG_STATUS, &status_reg, 1, dev);

        if (status_reg & BME280_STATUS_MEAS_DONE)
        {
            /* Measurement time delay given to read sample */
            dev->delay_us(period, dev->intf_ptr);

            /* Read compensated data */
            rslt = bme280_get_sensor_data(BME280_ALL, &comp_data, dev);
            printf(&comp_data);
            idx++;
        }
    }

    return rslt;
}