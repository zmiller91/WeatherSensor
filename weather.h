/**\
 * Copyright (c) 2020 Bosch Sensortec GmbH. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 **/

#ifndef _WEATHER_H
#define _WEATHER_H

#include <stdio.h>
#include "bme280.h"
#include <xc.h>
#include "mcc_generated_files/system/system.h"

#define WEATHER_OK                                      INT8_C(1)
#define WEATHER_TIMEOUT                                 INT8_C(-89)

void weather_init();
struct bme280_dev weather_dev();
int8_t weather_read(struct bme280_dev *dev, struct bme280_data *data);
bool weather_is_measurement_done(struct bme280_dev *dev);

/***************************************************************************/

/*!                 User function prototypes
 ****************************************************************************/

/*!
 *  @brief Function for reading the sensor's registers through I2C bus.
 *
 * @param[in] reg_addr       : Register address from which data is read.
 * @param[out] reg_data      : Pointer to data buffer where read data is stored.
 * @param[in] length         : Number of bytes of data to be read.
 * @param[in, out] intf_ptr  : Void pointer that can enable the linking of descriptors
 *                             for interface related call backs.
 *
 *  @return Status of execution
 *
 *  @retval BME280_INTF_RET_SUCCESS -> Success.
 *  @retval != BME280_INTF_RET_SUCCESS -> Failure.
 *
 */
BME280_INTF_RET_TYPE bme280_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t length, void *intf_ptr);

/*!
 *  @brief Function for writing the sensor's registers through I2C bus.
 *
 * @param[in] reg_addr      : Register address to which the data is written.
 * @param[in] reg_data      : Pointer to data buffer in which data to be written
 *                            is stored.
 * @param[in] length        : Number of bytes of data to be written.
 * @param[in, out] intf_ptr : Void pointer that can enable the linking of descriptors
 *                            for interface related call backs
 *
 *  @return Status of execution
 *
 *  @retval BME280_INTF_RET_SUCCESS -> Success.
 *  @retval != BME280_INTF_RET_SUCCESS -> Failure.
 *
 */
BME280_INTF_RET_TYPE bme280_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t length, void *intf_ptr);

/*!
 *  @brief This function provides the delay for required time (Microsecond) as per the input provided in some of the
 *  APIs.
 *
 *  @param[in] period_us  : The required wait time in microsecond.
 *  @param[in] intf_ptr   : Interface pointer
 *
 *  @return void.
 */
void bme280_delay_us(uint32_t period_us, void *intf_ptr);

#endif /* _COMMON_H */