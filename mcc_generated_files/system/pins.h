/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RB0 aliases
#define LED_TRIS                 TRISBbits.TRISB0
#define LED_LAT                  LATBbits.LATB0
#define LED_PORT                 PORTBbits.RB0
#define LED_WPU                  WPUBbits.WPUB0
#define LED_OD                   ODCONBbits.ODCB0
#define LED_ANS                  ANSELBbits.ANSB0
#define LED_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define LED_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define LED_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define LED_GetValue()           PORTBbits.RB0
#define LED_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define LED_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define LED_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/