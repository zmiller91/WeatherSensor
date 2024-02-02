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

// get/set IO_RA1 aliases
#define IO_RA1_TRIS                 TRISAbits.TRISA1
#define IO_RA1_LAT                  LATAbits.LATA1
#define IO_RA1_PORT                 PORTAbits.RA1
#define IO_RA1_WPU                  WPUAbits.WPUA1
#define IO_RA1_OD                   ODCONAbits.ODCA1
#define IO_RA1_ANS                  ANSELAbits.ANSA1
#define IO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_GetValue()           PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)
// get/set IO_RA2 aliases
#define DEV_PWR_TRIS                 TRISAbits.TRISA2
#define DEV_PWR_LAT                  LATAbits.LATA2
#define DEV_PWR_PORT                 PORTAbits.RA2
#define DEV_PWR_WPU                  WPUAbits.WPUA2
#define DEV_PWR_OD                   ODCONAbits.ODCA2
#define DEV_PWR_ANS                  ANSELAbits.ANSA2
#define DEV_PWR_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DEV_PWR_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DEV_PWR_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DEV_PWR_GetValue()           PORTAbits.RA2
#define DEV_PWR_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DEV_PWR_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DEV_PWR_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DEV_PWR_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DEV_PWR_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DEV_PWR_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DEV_PWR_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define DEV_PWR_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)
// get/set IO_RB5 aliases
#define UART_RX_TRIS                 TRISBbits.TRISB5
#define UART_RX_LAT                  LATBbits.LATB5
#define UART_RX_PORT                 PORTBbits.RB5
#define UART_RX_WPU                  WPUBbits.WPUB5
#define UART_RX_OD                   ODCONBbits.ODCB5
#define UART_RX_ANS                  ANSELBbits.ANSB5
#define UART_RX_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define UART_RX_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define UART_RX_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define UART_RX_GetValue()           PORTBbits.RB5
#define UART_RX_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define UART_RX_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define UART_RX_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define UART_RX_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define UART_RX_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define UART_RX_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define UART_RX_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define UART_RX_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)
// get/set IO_RC2 aliases
#define UART_TX_TRIS                 TRISCbits.TRISC2
#define UART_TX_LAT                  LATCbits.LATC2
#define UART_TX_PORT                 PORTCbits.RC2
#define UART_TX_WPU                  WPUCbits.WPUC2
#define UART_TX_OD                   ODCONCbits.ODCC2
#define UART_TX_ANS                  ANSELCbits.ANSC2
#define UART_TX_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define UART_TX_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define UART_TX_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define UART_TX_GetValue()           PORTCbits.RC2
#define UART_TX_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define UART_TX_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define UART_TX_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define UART_TX_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define UART_TX_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define UART_TX_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define UART_TX_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define UART_TX_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RD2 aliases
#define IO_SCL_TRIS                 TRISDbits.TRISD2
#define IO_SCL_LAT                  LATDbits.LATD2
#define IO_SCL_PORT                 PORTDbits.RD2
#define IO_SCL_WPU                  WPUDbits.WPUD2
#define IO_SCL_OD                   ODCONDbits.ODCD2
#define IO_SCL_ANS                  ANSELDbits.ANSD2
#define IO_SCL_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_SCL_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_SCL_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_SCL_GetValue()           PORTDbits.RD2
#define IO_SCL_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_SCL_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_SCL_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define IO_SCL_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define IO_SCL_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define IO_SCL_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define IO_SCL_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define IO_SCL_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)
// get/set IO_RD3 aliases
#define IO_SDA_TRIS                 TRISDbits.TRISD3
#define IO_SDA_LAT                  LATDbits.LATD3
#define IO_SDA_PORT                 PORTDbits.RD3
#define IO_SDA_WPU                  WPUDbits.WPUD3
#define IO_SDA_OD                   ODCONDbits.ODCD3
#define IO_SDA_ANS                  ANSELDbits.ANSD3
#define IO_SDA_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_SDA_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_SDA_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_SDA_GetValue()           PORTDbits.RD3
#define IO_SDA_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_SDA_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_SDA_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define IO_SDA_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define IO_SDA_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define IO_SDA_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define IO_SDA_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define IO_SDA_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)
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