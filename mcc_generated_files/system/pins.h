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

// get/set IO_RB1 aliases
#define IO_SCL_TRIS                 TRISBbits.TRISB1
#define IO_SCL_LAT                  LATBbits.LATB1
#define IO_SCL_PORT                 PORTBbits.RB1
#define IO_SCL_WPU                  WPUBbits.WPUB1
#define IO_SCL_OD                   ODCONBbits.ODCB1
#define IO_SCL_ANS                  ANSELBbits.ANSB1
#define IO_SCL_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_SCL_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_SCL_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_SCL_GetValue()           PORTBbits.RB1
#define IO_SCL_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_SCL_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_SCL_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_SCL_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_SCL_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_SCL_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_SCL_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define IO_SCL_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)
// get/set IO_RB2 aliases
#define IO_SDA_TRIS                 TRISBbits.TRISB2
#define IO_SDA_LAT                  LATBbits.LATB2
#define IO_SDA_PORT                 PORTBbits.RB2
#define IO_SDA_WPU                  WPUBbits.WPUB2
#define IO_SDA_OD                   ODCONBbits.ODCB2
#define IO_SDA_ANS                  ANSELBbits.ANSB2
#define IO_SDA_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_SDA_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_SDA_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_SDA_GetValue()           PORTBbits.RB2
#define IO_SDA_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_SDA_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_SDA_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_SDA_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_SDA_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_SDA_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_SDA_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define IO_SDA_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)
// get/set IO_RC6 aliases
#define UART_TX_TRIS                 TRISCbits.TRISC6
#define UART_TX_LAT                  LATCbits.LATC6
#define UART_TX_PORT                 PORTCbits.RC6
#define UART_TX_WPU                  WPUCbits.WPUC6
#define UART_TX_OD                   ODCONCbits.ODCC6
#define UART_TX_ANS                  ANSELCbits.ANSC6
#define UART_TX_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define UART_TX_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define UART_TX_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define UART_TX_GetValue()           PORTCbits.RC6
#define UART_TX_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define UART_TX_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define UART_TX_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define UART_TX_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define UART_TX_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define UART_TX_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define UART_TX_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define UART_TX_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)
// get/set IO_RC7 aliases
#define UART_RX_TRIS                 TRISCbits.TRISC7
#define UART_RX_LAT                  LATCbits.LATC7
#define UART_RX_PORT                 PORTCbits.RC7
#define UART_RX_WPU                  WPUCbits.WPUC7
#define UART_RX_OD                   ODCONCbits.ODCC7
#define UART_RX_ANS                  ANSELCbits.ANSC7
#define UART_RX_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define UART_RX_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define UART_RX_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define UART_RX_GetValue()           PORTCbits.RC7
#define UART_RX_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define UART_RX_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define UART_RX_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define UART_RX_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define UART_RX_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define UART_RX_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define UART_RX_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define UART_RX_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)
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