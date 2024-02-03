/*
 * File:   timeout.c
 * Author: zmiller
 *
 * Created on February 2, 2024, 3:06 PM
 */


#include <xc.h>
#include "timeout.h"
#include "timeout.h"

#include "mcc_generated_files/timer/tmr6.h"

// Timer overflows every 50 milliseconds. 40 overflows us 2 seconds.
uint8_t MAX_OVERFLOWS = 40;
uint8_t OVERFLOW_COUNT = 0;

bool timeout_wait(bool (* StatusHandler)(void)) {
    timeout_start();
    while(StatusHandler() && !timeout_timed_out());
    timeout_stop();
    return !timeout_timed_out();
}

void timeout_init(void){
    TMR6_OverflowCallbackRegister(timer_increment);
}

void timeout_start(void){
    timeot_reset();
    TMR6_Start();
}

void timeout_stop(void) {
    TMR6_Stop();
}

void timeot_reset(void) {
    // clear the TMR6 interrupt flag
    PIR2bits.TMR6IF = 0;
    OVERFLOW_COUNT = 0;
}

bool timeout_timed_out(void) {
    return OVERFLOW_COUNT >= MAX_OVERFLOWS;
}

void timer_increment(void) {
    OVERFLOW_COUNT++;
    if(timeout_timed_out()) {
        timeout_stop();
    }
}