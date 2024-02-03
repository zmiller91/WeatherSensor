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
#include "weather.h"
#include "bme280.h"
#include "rylr998.h"
#include "timeout.h"



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

void write_eeprom(uint16_t address, char *data, uint8_t size) {
    
    NVM_UnlockKeySet(0xaa55);
    for(uint8_t i = 0; i < size; i++) {   
        while(NVM_IsBusy());
        EEPROM_Write(address + i, data[i]);
    }
}

void read_eeprom(uint16_t address, char data[], uint8_t size) {
    
    NVM_UnlockKeySet(0xaa55);
    for(uint8_t i = 0; i < size; i++) {   
        while(NVM_IsBusy());
        data[i] = EEPROM_Read(address + i);
    }
}

int main(void){
    
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    // Retrieve the serial number from EEPROM. We are writing to it first because
    // MPLAB will reset the EEPROM memory when it flashes the chip. There is
    // config to not do that, but it doesn't appear to work.
    char serial_number[9] = {0};
    write_eeprom(0xF000, "ABCDEFGH", 8);
    read_eeprom(0xF000, serial_number, 8);
    serial_number[8] = '\0'; // needs to be null terminated
      
    while(1) {
    
        rylr998_init();
        weather_init();
        
        // Turn the devices on and wait a second so they can power up.
        DEV_PWR_SetHigh();
        __delay_ms(1000);
        
        struct bme280_data weather;
        struct bme280_dev dev = weather_dev();
        int8_t response_code = weather_read(&dev, &weather);
        if(response_code > 0) {
            rylr998_send(32, serial_number, "TEMPERATURE", weather.temperature);
            __delay_ms(1000);

            rylr998_send(32, serial_number, "HUMIDITY", weather.humidity);
            __delay_ms(1000);

            rylr998_send(32, serial_number, "PRESSURE", weather.pressure);
            __delay_ms(1000);
        }
        
        // Turn the devices off so they don't draw any current.
        DEV_PWR_SetLow();
        
        // Turn the watchdog timer on for a handful of SLEEP cycles and then
        // turn the timer off so the process can be restarted.
        //WDTSEN ON; WDTPS 1:262144; WDTCS LFINTOSC (31 kHz); 
        WDTCON = 0x1B;
        for(uint8_t i = 0; i < 114; i++) {
            SLEEP();
        }
        WDTCON = 0x1A;
        
    }    
}