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
bool TIMED_OUT = true;

void timeout_init(){
    TMR6_OverflowCallbackRegister(timer_increment);
}

void timeout_start(){
    timeot_reset();
    TMR6_Start();
}

void timeout_stop() {
    TMR6_Stop();
}

void timeot_reset() {
    // clear the TMR6 interrupt flag
    PIR2bits.TMR6IF = 0;
    OVERFLOW_COUNT = 0;
    TIMED_OUT = false;
}

bool timeout_timed_out() {
    return TIMED_OUT;
}

void timer_increment() {
    OVERFLOW_COUNT++;
    TIMED_OUT = OVERFLOW_COUNT >= MAX_OVERFLOWS;
    if(TIMED_OUT) {
        timeout_stop();
    }
}