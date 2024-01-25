/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_RYLR998_H
#define	XC_HEADER_RYLR998_H

#include <xc.h> // include processor files - each processor file is guarded.  

/*! @name RYLR998 Error Codes */
#define RYLR998_NO_ENTER                                INT8_C(-1)
#define RYLR998_NO_AT                                   INT8_C(-2)
#define RYLR998_UNKNOWN_CMD                             INT8_C(-4)
#define RYLR998_LEN_MISMATCH                            INT8_C(-5)
#define RYLR998_TX_OVER_TIMES                           INT8_C(-10)
#define RYLR998_CRC_ERROR                               INT8_C(-12)
#define RYLR998_TX_EXCEEDS_240B                         INT8_C(-13)
#define RYLR998_FLASH_WRITE_FAILED                      INT8_C(-14)
#define RYLR998_UNKNOWN_FAILURE                         INT8_C(-15)
#define RYLR998_LAST_TX_NOT_COMPLETE                    INT8_C(-17)
#define RYLR998_PREAMBLE_VAL_NOT_ALLOWED                INT8_C(-18)
#define RYLR998_RX_FAILED_HEADER_ERROR                  INT8_C(-19)
#define RYLR998_TIME_SETTING_NOT_ALLOWED                INT8_C(-20)
#define RYLR998_UNLISTED_FAILURE                        INT8_C(-99)

void rylr998_init();
void rylr998_send(uint8_t address, char tag[], double metric);
void rylr998_write(char data[]);
void rylr998_read();


#endif	/* XC_HEADER_TEMPLATE_H */

