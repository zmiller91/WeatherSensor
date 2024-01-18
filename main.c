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

#define DHT11_PIN      RB4
#define DHT11_PIN_DIR  TRISB4

#include <stdint.h>
#include <stdbool.h>

#include <string.h>
#include <xc.h>
#include "mcc_generated_files/system/system.h"

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

uint8_t TIMEOUT = 100;
uint8_t DHT11_ERROR = 101;
uint8_t DHT11_OK = 202;

uint8_t parseDHT11Byte(uint8_t byteArray[], uint8_t byte);
void dht11Start();
uint8_t dht11CheckResponse();

int main(void)
{
    SYSTEM_Initialize();
    LED_SetHigh();
    
    
    __delay_ms(1000);
    IO_RB5_SetDigitalOutput();
    IO_RB5_SetHigh();
    IO_RB5_SetPullup();
    __delay_ms(1000);
    
    while(1)
    {
        // Start signal
        INTERRUPT_GlobalInterruptDisable();
        IO_RB5_SetDigitalOutput();
        IO_RB5_SetHigh();
      
        
        IO_RB5_SetLow();
        __delay_ms(30);
        
        IO_RB5_SetHigh();
        __delay_us(40);
        
        IO_RB5_SetDigitalInput();
        
        // Wait while voltage is high
        while(IO_RB5_GetValue());
        
        // DHT pulled down pin as it's response. It'll be pulled down for 80us
        // Wait while voltage is low
        while(!IO_RB5_GetValue());
        
        // DHT pulled up pin as it's response. It'll be pulled up for 80s
        // Wait while voltage is high 
        while(IO_RB5_GetValue());
        
        // DHT pulled down pin to start transmission
        uint8_t data[80];
        for(uint8_t i = 0; i < 80; i = i + 2) {

            // Wait while the pin is pulled back up
            uint8_t lowTick = 0;
            while(!IO_RB5_GetValue() && lowTick < 100) {
                lowTick++;
            }

            uint8_t highTick = 0;
            while(IO_RB5_GetValue() && highTick < 100) {
                highTick++;
            }

            data[i] = lowTick;
            data[i + 1] = highTick;
        }
        
        uint8_t humidity = parseDHT11Byte(data, (uint8_t) 0);
        uint8_t humidityDecimal = parseDHT11Byte(data, (uint8_t) 1);
        uint8_t temp = parseDHT11Byte(data, (uint8_t) 2);
        uint8_t tempDecimal = parseDHT11Byte(data, (uint8_t) 3);
        
        printf(humidity);
        printf(humidityDecimal);
        printf(temp);
        printf(tempDecimal);
        free(data);        
    }    
}

/**
 * The DHT11 is started by setting the GPIO pin to LOW for at least 18ms and 
 * then pulling the GPIO pin to HIGH for 20-40us. 
 * 
 * @return 
 */
uint8_t dht11Start() {
    
    // Turn off global interrupts since the DHT11 sequence is timing critical
    INTERRUPT_GlobalInterruptDisable();
    
    // Turn the GPIO pin to high to ensure DHT11 will receive LOW signal
    IO_RB5_SetDigitalOutput();
    IO_RB5_SetHigh();
    __delay_ms(30);

    // Turn the GPIO pin to LOW for 30 ms, per the DHT11 data sheet
    IO_RB5_SetLow();
    __delay_ms(30);

    // Turn the GPIO pin to HIGH for 40us, per the DHT11 data sheet
    IO_RB5_SetHigh();
    __delay_us(40);

    IO_RB5_SetDigitalInput();
}

uint8_t dht11CheckResponse() {
    
    // Wait while the GPIO pin is high. After the start sequence the DHT11
    // will pull it to LOW. 
    uint8_t tick = 0;
    while(IO_RB5_GetValue()) {
        if(tick > TIMEOUT) {
            return DHT11_ERROR;
        }
        
        tick++;
    };

    // DHT11 pulled the GPIO pin as low. It will keep it here for 80us.
    tick = 0;
    while(!IO_RB5_GetValue()) {
        if(tick > TIMEOUT) {
            return DHT11_ERROR;
        }
        
        tick++;
    };

    // DHT11 pulled the GPIO pin to HIGH. It will keep it here for 80us.
    tick = 0;
    while(IO_RB5_GetValue()) {
        if(tick > TIMEOUT) {
            return DHT11_ERROR;
        }
        
        tick++;
    };
    
    // The DHT11 pulled the GPIO pin back to LOW to start data transmission. 
    return DHT11_OK;
}

uint8_t parseDHT11Byte(uint8_t byteArray[], uint8_t byte) {
    
    uint8_t startPos = 16 * byte;
    uint8_t result = 0;
    uint8_t idx = 0;
    for(uint8_t i = startPos; i < startPos + 16; i = i + 2) {

        uint8_t low = byteArray[i];
        uint8_t high = byteArray[i + 1];
        if (low < high) {
            uint8_t _bit = ((uint8_t)1) << (7 - idx);
            result = result | _bit; 
        }

        idx++;    
    }
    
    return result;
}