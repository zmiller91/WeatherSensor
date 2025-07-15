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

volatile uint16_t overflowCount = 0;

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

void MyTimer1Handler(void){
    overflowCount++;
}

void low_power_mode(void){

    // Turn the devices off so they don't draw any current.
    DEV_PWR_SetLow();
    
    ADCON0bits.ADON = 0;     // Disable ADC
    FVRCONbits.FVREN = 0;     // Disable FVR
    T6CONbits.TMR6ON = 0;     // Disable Timer6

    // Turn the timer 1 on for a handful of SLEEP cycles and then
    // turn the timer off so the process can be restarted.
    TMR1_Start();
    overflowCount = 0;
    while (overflowCount < 114) {
        SLEEP();  // Wait for interrupt
        NOP();
    }

    TMR1_Stop();
    FVRCONbits.FVREN = 1;
    ADCON0bits.ADON = 1;
    T6CONbits.TMR6ON = 1;
}

int main(void){

    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR1_OverflowCallbackRegister(MyTimer1Handler); 
    
    // Retrieve the serial number from EEPROM. We are writing to it first because
    // MPLAB will reset the EEPROM memory when it flashes the chip. There is
    // config to not do that, but it doesn't appear to work.
    char serial_number[9] = {0};
    write_eeprom(0xF000, "ABCDEFGH", 8);
    read_eeprom(0xF000, serial_number, 8);
    serial_number[8] = '\0'; // needs to be null terminated  
    
    IO_RC4_SetDigitalInput();
    IO_RC4_SetAnalogMode();   
    
    while(1) { 

        rylr998_init();
        weather_init();
        
        // Turn the devices on and wait a second so they can power up.
        DEV_PWR_SetHigh();
        __delay_ms(1000);
        
        struct bme280_data weather;
        struct bme280_dev dev = weather_dev();
        int8_t response_code = weather_read(&dev, &weather);
            
        // Rylr needs a minimum of 2.5v
        adc_result_t result = ADCC_GetSingleConversion(channel_ANC4);
        
        float max_bat_voltage = 3.0f; // Full battery voltage
        float min_bat_voltage = 2.5f; // Minimum voltage needed for all components to work
        float allowable_voltage_drop = max_bat_voltage - min_bat_voltage;
        float adc_voltage = result / 1023.0f * 1.024f;
        float battery_voltage = adc_voltage / 0.266f;
        float bat_pct = (battery_voltage - min_bat_voltage) / allowable_voltage_drop * 100.0f;
        
        if (bat_pct > 100.0f) bat_pct = 100.0f;
        if (bat_pct < 0.0f)   bat_pct = 0.0f;
        
        if(response_code > 0) {
            
            double payload[4] = {
                weather.temperature, 
                weather.humidity, 
                weather.pressure,
                bat_pct};
            
            rylr998_send_flat(32, serial_number, payload, 4);
        }
        
        low_power_mode();

    }    
}


