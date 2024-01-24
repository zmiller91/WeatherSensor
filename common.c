/**
 * Copyright (C) 2020 Bosch Sensortec GmbH. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "bme280.h"
#include "common.h"

/******************************************************************************/
/*!                               Macros                                      */

#define BME280_SHUTTLE_ID  UINT8_C(0x33)

/******************************************************************************/
/*!                Static variable definition                                 */

/*! Variable that holds the I2C device address or SPI chip selection */
static uint8_t dev_addr;

/******************************************************************************/
/*!                User interface functions                                   */

/*!
 * I2C read function map to PIC platform
 */
BME280_INTF_RET_TYPE bme280_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t length, void *intf_ptr)
{
    
    if(!I2C2_WriteRead(dev_addr, &reg_addr, 1, reg_data, length)){
        return BME280_E_COMM_FAIL;
    }
    
    while(I2C2_IsBusy());
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
    
    while(I2C2_IsBusy());
    return BME280_INTF_RET_SUCCESS;
}

/*!
 * SPI read function map to PIC platform
 */
BME280_INTF_RET_TYPE bme280_spi_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t length, void *intf_ptr)
{
    return 0;
}

/*!
 * SPI write function map to PIC platform
 */
BME280_INTF_RET_TYPE bme280_spi_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t length, void *intf_ptr)
{
    return 0;
}

/*!
 * Delay function map to PIC platform
 */
void bme280_delay_us(uint32_t period, void *intf_ptr)
{
    __delay_us(1000);
}

/*!
 *  @brief Prints the execution status of the APIs.
 */
void bme280_error_codes_print_result(const char api_name[], int8_t rslt)
{
    if (rslt != BME280_OK)
    {
        printf("%s\t", api_name);

        switch (rslt)
        {
            case BME280_E_NULL_PTR:
                printf("Error [%d] : Null pointer error.", rslt);
                printf(
                    "It occurs when the user tries to assign value (not address) to a pointer, which has been initialized to NULL.\r\n");
                break;

            case BME280_E_COMM_FAIL:
                printf("Error [%d] : Communication failure error.", rslt);
                printf(
                    "It occurs due to read/write operation failure and also due to power failure during communication\r\n");
                break;

            case BME280_E_DEV_NOT_FOUND:
                printf("Error [%d] : Device not found error. It occurs when the device chip id is incorrectly read\r\n",
                       rslt);
                break;

            case BME280_E_INVALID_LEN:
                printf("Error [%d] : Invalid length error. It occurs when write is done with invalid length\r\n", rslt);
                break;

            default:
                printf("Error [%d] : Unknown error code\r\n", rslt);
                break;
        }
    }
}

/*!
 *  @brief Function to select the interface between SPI and I2C.
 */
int8_t bme280_interface_selection(struct bme280_dev *dev, uint8_t intf)
{
    int8_t rslt = BME280_OK;

    if (dev != NULL)
    {

        /* Bus configuration : I2C */
        if (intf == BME280_I2C_INTF)
        {
            printf("I2C Interface\n");

            dev_addr = BME280_I2C_ADDR_PRIM;
            dev->read = bme280_i2c_read;
            dev->write = bme280_i2c_write;
            dev->intf = BME280_I2C_INTF;
        }

        /* Holds the I2C device addr or SPI chip selection */
        dev->intf_ptr = &dev_addr;

        /* Configure delay in microseconds */
        dev->delay_us = bme280_delay_us;
    }
    else
    {
        rslt = BME280_E_NULL_PTR;
    }

    return rslt;
}

/*!
 *  @brief Function deinitializes coines platform.
 */
void bme280_coines_deinit(void)
{
//    coines_close_comm_intf(COINES_COMM_INTF_USB, NULL);
}