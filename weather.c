/**
 * Copyright (C) 2020 Bosch Sensortec GmbH. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "bme280.h"
#include "weather.h"
#include "timeout.h"

/******************************************************************************/
/*!                               Macros                                      */

#define BME280_SHUTTLE_ID  UINT8_C(0x33)

/******************************************************************************/
/*!                Static variable definition                                 */

/*! Variable that holds the I2C device address or SPI chip selection */
static uint8_t dev_addr;

/******************************************************************************/
/*!                User interface functions                                   */




void weather_init() {
    IO_SCL_SetDigitalMode();
    IO_SCL_SetPullup();
    IO_SDA_SetDigitalMode();
    IO_SDA_SetPullup();
    timeout_init();
}

struct bme280_dev weather_dev() { 
    
    int8_t rslt;
    struct bme280_dev dev;
    struct bme280_settings settings;

    // Setup I2C interface
    dev_addr = BME280_I2C_ADDR_PRIM;
    dev.read = bme280_i2c_read;
    dev.write = bme280_i2c_write;
    dev.intf = BME280_I2C_INTF;
    dev.intf_ptr = &dev_addr;
    dev.delay_us = bme280_delay_us;
    
    // Initialize device and update settings
    rslt = bme280_init(&dev);
    rslt = bme280_get_sensor_settings(&settings, &dev);

    /* Configuring the over-sampling rate, filter coefficient and standby time */
    /* Overwrite the desired settings */
    settings.filter = BME280_FILTER_COEFF_OFF;

    /* Over-sampling rate for humidity, temperature and pressure */
    settings.osr_h = BME280_OVERSAMPLING_1X;
    settings.osr_p = BME280_OVERSAMPLING_1X;
    settings.osr_t = BME280_OVERSAMPLING_1X;

    /* Setting the standby time */
    settings.standby_time = BME280_STANDBY_TIME_0_5_MS;

    rslt = bme280_set_sensor_settings(BME280_SEL_ALL_SETTINGS, &settings, &dev);
    rslt = bme280_set_sensor_mode(BME280_POWERMODE_SLEEP, &dev);
    
    return dev;
}


/*!
 *  @brief This internal API is used to get compensated temperature data.
 */
int8_t weather_read(struct bme280_dev *dev, struct bme280_data *weather)
{
    int8_t rslt = BME280_E_NULL_PTR;
    
    // Force a reading and wait a second for the measurement
    rslt = bme280_set_sensor_mode(BME280_POWERMODE_NORMAL, dev);
    if(rslt != BME280_OK) {
        return rslt;
    }
    
    __delay_ms(1000);
    
    timeout_start();
    while(!weather_is_measurement_done(dev) && !timeout_timed_out()) {
        __delay_ms(100);
    }
    
    timeout_stop();
    if(timeout_timed_out()) {
        return WEATHER_TIMEOUT;
    }
    
    // Get the results
    rslt = bme280_get_sensor_data(BME280_ALL, weather, dev);
    if(rslt != BME280_OK) {
        return rslt;
    }
    
    return WEATHER_OK;
}

bool weather_is_measurement_done(struct bme280_dev *dev) {
    uint8_t status_reg;
    int8_t rslt = bme280_get_regs(BME280_REG_STATUS, &status_reg, 1, dev);
    return !(status_reg & BME280_STATUS_MEAS_DONE);
}


/**
 * 
 * 
 * Everything below here are implementation methods so the PIC can work with
 * the BME280 device driver. Note
 * 
 *  
 */



/*!
 * I2C read function map to PIC platform
 */
BME280_INTF_RET_TYPE bme280_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t length, void *intf_ptr)
{
    
    if(!I2C2_WriteRead(dev_addr, &reg_addr, 1, reg_data, length)){
        return BME280_E_COMM_FAIL;
    }
    
    timeout_start();
    while(I2C2_IsBusy() && !timeout_timed_out());
    timeout_stop();
    if(timeout_timed_out()) {
        return BME280_E_COMM_FAIL;
    }
    
    printf(reg_data);
    return BME280_INTF_RET_SUCCESS;
}

/*!
 * I2C write function map to PIC platform
 */
BME280_INTF_RET_TYPE bme280_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t length, void *intf_ptr)
{
    uint8_t buf[BME280_MAX_LEN * 2] = {0};
    buf[0] = reg_addr;
    for(uint8_t i = 0; i < length + 1; i++) {
        buf[i + 1] = reg_data[i];
    }
    
    // TODO: Do something with this error
    if(!I2C2_Write(dev_addr, &buf, length + 1)) {
        return BME280_E_COMM_FAIL;
    }
    
    timeout_start();
    while(I2C2_IsBusy() && !timeout_timed_out());
    timeout_stop();
    if(timeout_timed_out()) {
        return BME280_E_COMM_FAIL;
    }
    
    return BME280_INTF_RET_SUCCESS;
}

/*!
 * Delay function map to PIC platform
 */
void bme280_delay_us(uint32_t period, void *intf_ptr)
{
    //TODO: This needs to be changed to something real. But for some reason
    // I can't use variable length data.
    __delay_us(1000);
}