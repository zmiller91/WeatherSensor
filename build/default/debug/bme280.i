# 1 "bme280.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v6.10/packs/Microchip/PIC16F1xxxx_DFP/1.18.352/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "bme280.c" 2
# 42 "bme280.c"
# 1 "./bme280.h" 1
# 50 "./bme280.h"
# 1 "./bme280_defs.h" 1
# 43 "./bme280_defs.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\musl_xc8.h" 1 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 23 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 145 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stdint.h" 2 3
# 43 "./bme280_defs.h" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stddef.h" 1 3
# 19 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stddef.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 18 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 122 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 132 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\bits/alltypes.h" 3
typedef int ptrdiff_t;
# 20 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c99\\stddef.h" 2 3
# 44 "./bme280_defs.h" 2
# 259 "./bme280_defs.h"
enum bme280_intf {

    BME280_SPI_INTF,

    BME280_I2C_INTF
};
# 284 "./bme280_defs.h"
typedef int8_t (*bme280_read_fptr_t)(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, void *intf_ptr);
# 301 "./bme280_defs.h"
typedef int8_t (*bme280_write_fptr_t)(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len,
                                                    void *intf_ptr);
# 313 "./bme280_defs.h"
typedef void (*bme280_delay_us_fptr_t)(uint32_t period, void *intf_ptr);
# 322 "./bme280_defs.h"
struct bme280_calib_data
{

    uint16_t dig_t1;


    int16_t dig_t2;


    int16_t dig_t3;


    uint16_t dig_p1;


    int16_t dig_p2;


    int16_t dig_p3;


    int16_t dig_p4;


    int16_t dig_p5;


    int16_t dig_p6;


    int16_t dig_p7;


    int16_t dig_p8;


    int16_t dig_p9;


    uint8_t dig_h1;


    int16_t dig_h2;


    uint8_t dig_h3;


    int16_t dig_h4;


    int16_t dig_h5;


    int8_t dig_h6;


    int32_t t_fine;
};






struct bme280_data
{

    double pressure;


    double temperature;


    double humidity;
};
# 416 "./bme280_defs.h"
struct bme280_uncomp_data
{

    uint32_t pressure;


    uint32_t temperature;


    uint32_t humidity;
};





struct bme280_settings
{

    uint8_t osr_p;


    uint8_t osr_t;


    uint8_t osr_h;


    uint8_t filter;


    uint8_t standby_time;
};




struct bme280_dev
{

    uint8_t chip_id;





    enum bme280_intf intf;







    void *intf_ptr;


    int8_t intf_rslt;


    bme280_read_fptr_t read;


    bme280_write_fptr_t write;


    bme280_delay_us_fptr_t delay_us;


    struct bme280_calib_data calib_data;
};
# 50 "./bme280.h" 2
# 77 "./bme280.h"
int8_t bme280_init(struct bme280_dev *dev);
# 106 "./bme280.h"
int8_t bme280_set_regs(uint8_t *reg_addr, const uint8_t *reg_data, uint32_t len, struct bme280_dev *dev);
# 128 "./bme280.h"
int8_t bme280_get_regs(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, struct bme280_dev *dev);
# 171 "./bme280.h"
int8_t bme280_set_sensor_settings(uint8_t desired_settings,
                                  const struct bme280_settings *settings,
                                  struct bme280_dev *dev);
# 194 "./bme280.h"
int8_t bme280_get_sensor_settings(struct bme280_settings *settings, struct bme280_dev *dev);
# 228 "./bme280.h"
int8_t bme280_set_sensor_mode(uint8_t sensor_mode, struct bme280_dev *dev);
# 256 "./bme280.h"
int8_t bme280_get_sensor_mode(uint8_t *sensor_mode, struct bme280_dev *dev);
# 281 "./bme280.h"
int8_t bme280_soft_reset(struct bme280_dev *dev);
# 290 "./bme280.h"
int8_t bme280_get_sensor_data(uint8_t sensor_comp, struct bme280_data *comp_data, struct bme280_dev *dev);
# 320 "./bme280.h"
int8_t bme280_compensate_data(uint8_t sensor_comp,
                              const struct bme280_uncomp_data *uncomp_data,
                              struct bme280_data *comp_data,
                              struct bme280_calib_data *calib_data);
# 352 "./bme280.h"
int8_t bme280_cal_meas_delay(uint32_t *max_delay, const struct bme280_settings *settings);
# 42 "bme280.c" 2
# 63 "bme280.c"
static int8_t put_device_to_sleep(struct bme280_dev *dev);
# 78 "bme280.c"
static int8_t write_power_mode(uint8_t sensor_mode, struct bme280_dev *dev);
# 93 "bme280.c"
static int8_t null_ptr_check(const struct bme280_dev *dev);
# 107 "bme280.c"
static void interleave_reg_addr(const uint8_t *reg_addr, uint8_t *temp_buff, const uint8_t *reg_data, uint32_t len);
# 122 "bme280.c"
static int8_t get_calib_data(struct bme280_dev *dev);
# 132 "bme280.c"
static void parse_temp_press_calib_data(const uint8_t *reg_data, struct bme280_dev *dev);
# 142 "bme280.c"
static void parse_humidity_calib_data(const uint8_t *reg_data, struct bme280_dev *dev);
# 158 "bme280.c"
static uint8_t are_settings_changed(uint8_t sub_settings, uint8_t desired_settings);
# 174 "bme280.c"
static int8_t set_osr_humidity_settings(const struct bme280_settings *settings, struct bme280_dev *dev);
# 193 "bme280.c"
static int8_t set_osr_settings(uint8_t desired_settings, const struct bme280_settings *settings,
                               struct bme280_dev *dev);
# 213 "bme280.c"
static int8_t set_osr_press_temp_settings(uint8_t desired_settings,
                                          const struct bme280_settings *settings,
                                          struct bme280_dev *dev);
# 227 "bme280.c"
static void fill_osr_press_settings(uint8_t *reg_data, const struct bme280_settings *settings);
# 239 "bme280.c"
static void fill_osr_temp_settings(uint8_t *reg_data, const struct bme280_settings *settings);
# 257 "bme280.c"
static int8_t set_filter_standby_settings(uint8_t desired_settings,
                                          const struct bme280_settings *settings,
                                          struct bme280_dev *dev);
# 271 "bme280.c"
static void fill_filter_settings(uint8_t *reg_data, const struct bme280_settings *settings);
# 283 "bme280.c"
static void fill_standby_settings(uint8_t *reg_data, const struct bme280_settings *settings);
# 295 "bme280.c"
static void parse_device_settings(const uint8_t *reg_data, struct bme280_settings *settings);
# 304 "bme280.c"
static void parse_sensor_data(const uint8_t *reg_data, struct bme280_uncomp_data *uncomp_data);
# 321 "bme280.c"
static int8_t reload_device_settings(const struct bme280_settings *settings, struct bme280_dev *dev);
# 335 "bme280.c"
static double compensate_pressure(const struct bme280_uncomp_data *uncomp_data,
                                  const struct bme280_calib_data *calib_data);
# 348 "bme280.c"
static double compensate_humidity(const struct bme280_uncomp_data *uncomp_data,
                                  const struct bme280_calib_data *calib_data);
# 361 "bme280.c"
static double compensate_temperature(const struct bme280_uncomp_data *uncomp_data,
                                     struct bme280_calib_data *calib_data);
# 413 "bme280.c"
int8_t bme280_init(struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t chip_id = 0;


    rslt = bme280_get_regs(0xD0, &chip_id, 1, dev);


    if (rslt == 0)
    {
        if (chip_id == 0x60)
        {
            dev->chip_id = chip_id;


            rslt = bme280_soft_reset(dev);

            if (rslt == 0)
            {

                rslt = get_calib_data(dev);
            }
        }
        else
        {
            rslt = -4;
        }
    }

    return rslt;
}




int8_t bme280_get_regs(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, struct bme280_dev *dev)
{
    int8_t rslt;


    rslt = null_ptr_check(dev);

    if ((rslt == 0) && (reg_data != ((void*)0)))
    {

        if (dev->intf != BME280_I2C_INTF)
        {
            reg_addr = reg_addr | 0x80;
        }


        dev->intf_rslt = dev->read(reg_addr, reg_data, len, dev->intf_ptr);


        if (dev->intf_rslt != 0)
        {
            rslt = -2;
        }
    }
    else
    {
        rslt = -1;
    }

    return rslt;
}





int8_t bme280_set_regs(uint8_t *reg_addr, const uint8_t *reg_data, uint32_t len, struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t temp_buff[20];
    uint32_t temp_len;
    uint32_t reg_addr_cnt;

    if (len > 10)
    {
        len = 10;
    }


    rslt = null_ptr_check(dev);


    if ((rslt == 0) && (reg_addr != ((void*)0)) && (reg_data != ((void*)0)))
    {
        if (len != 0)
        {
            temp_buff[0] = reg_data[0];


            if (dev->intf != BME280_I2C_INTF)
            {
                for (reg_addr_cnt = 0; reg_addr_cnt < len; reg_addr_cnt++)
                {
                    reg_addr[reg_addr_cnt] = reg_addr[reg_addr_cnt] & 0x7F;
                }
            }


            if (len > 1)
            {



                interleave_reg_addr(reg_addr, temp_buff, reg_data, len);
                temp_len = ((len * 2) - 1);
            }
            else
            {
                temp_len = len;
            }

            dev->intf_rslt = dev->write(reg_addr[0], temp_buff, temp_len, dev->intf_ptr);


            if (dev->intf_rslt != 0)
            {
                rslt = -2;
            }
        }
        else
        {
            rslt = -3;
        }
    }
    else
    {
        rslt = -1;
    }

    return rslt;
}





int8_t bme280_set_sensor_settings(uint8_t desired_settings,
                                  const struct bme280_settings *settings,
                                  struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t sensor_mode;

    if (settings != ((void*)0))
    {
        rslt = bme280_get_sensor_mode(&sensor_mode, dev);

        if ((rslt == 0) && (sensor_mode != 0x00))
        {
            rslt = put_device_to_sleep(dev);
        }

        if (rslt == 0)
        {



            if (are_settings_changed(0x07, desired_settings))
            {
                rslt = set_osr_settings(desired_settings, settings, dev);
            }




            if ((rslt == 0) && are_settings_changed(0x18, desired_settings))
            {
                rslt = set_filter_standby_settings(desired_settings, settings, dev);
            }
        }
    }
    else
    {
        rslt = -1;
    }

    return rslt;
}





int8_t bme280_get_sensor_settings(struct bme280_settings *settings, struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t reg_data[4];

    if (settings != ((void*)0))
    {
        rslt = bme280_get_regs(0xF2, reg_data, 4, dev);

        if (rslt == 0)
        {
            parse_device_settings(reg_data, settings);
        }
    }
    else
    {
        rslt = -1;
    }

    return rslt;
}




int8_t bme280_set_sensor_mode(uint8_t sensor_mode, struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t last_set_mode;

    rslt = bme280_get_sensor_mode(&last_set_mode, dev);




    if ((rslt == 0) && (last_set_mode != 0x00))
    {
        rslt = put_device_to_sleep(dev);
    }


    if (rslt == 0)
    {
        rslt = write_power_mode(sensor_mode, dev);
    }

    return rslt;
}




int8_t bme280_get_sensor_mode(uint8_t *sensor_mode, struct bme280_dev *dev)
{
    int8_t rslt;

    if (sensor_mode != ((void*)0))
    {

        rslt = bme280_get_regs(0xF4, sensor_mode, 1, dev);


        *sensor_mode = (*sensor_mode & ( 0x03));
    }
    else
    {
        rslt = -1;
    }

    return rslt;
}




int8_t bme280_soft_reset(struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t reg_addr = 0xE0;
    uint8_t status_reg = 0;
    uint8_t try_run = 5;


    uint8_t soft_rst_cmd = 0xB6;


    rslt = bme280_set_regs(&reg_addr, &soft_rst_cmd, 1, dev);

    if (rslt == 0)
    {

        do
        {

            dev->delay_us(2000, dev->intf_ptr);
            rslt = bme280_get_regs(0xF3, &status_reg, 1, dev);

        } while ((rslt == 0) && (try_run--) && (status_reg & 0x01));

        if (status_reg & 0x01)
        {
            rslt = -6;
        }
    }

    return rslt;
}






int8_t bme280_get_sensor_data(uint8_t sensor_comp, struct bme280_data *comp_data, struct bme280_dev *dev)
{
    int8_t rslt;




    uint8_t reg_data[8] = { 0 };
    struct bme280_uncomp_data uncomp_data = { 0 };

    if (comp_data != ((void*)0))
    {

        rslt = bme280_get_regs(0xF7, reg_data, 8, dev);

        if (rslt == 0)
        {

            parse_sensor_data(reg_data, &uncomp_data);




            rslt = bme280_compensate_data(sensor_comp, &uncomp_data, comp_data, &dev->calib_data);
        }
    }
    else
    {
        rslt = -1;
    }

    return rslt;
}






int8_t bme280_compensate_data(uint8_t sensor_comp,
                              const struct bme280_uncomp_data *uncomp_data,
                              struct bme280_data *comp_data,
                              struct bme280_calib_data *calib_data)
{
    int8_t rslt = 0;

    if ((uncomp_data != ((void*)0)) && (comp_data != ((void*)0)) && (calib_data != ((void*)0)))
    {

        comp_data->temperature = 0;
        comp_data->pressure = 0;
        comp_data->humidity = 0;


        if (sensor_comp & (1 | 1 << 1 | 1 << 2))
        {

            comp_data->temperature = compensate_temperature(uncomp_data, calib_data);
        }

        if (sensor_comp & 1)
        {

            comp_data->pressure = compensate_pressure(uncomp_data, calib_data);
        }

        if (sensor_comp & 1 << 2)
        {

            comp_data->humidity = compensate_humidity(uncomp_data, calib_data);
        }
    }
    else
    {
        rslt = -1;
    }

    return rslt;
}





int8_t bme280_cal_meas_delay(uint32_t *max_delay, const struct bme280_settings *settings)
{
    int8_t rslt = 0;
    uint8_t temp_osr;
    uint8_t pres_osr;
    uint8_t hum_osr;


    uint8_t osr_sett_to_act_osr[] = { 0, 1, 2, 4, 8, 16 };

    if ((settings != ((void*)0)) && (max_delay != ((void*)0)))
    {

        if (settings->osr_t <= 0x05)
        {
            temp_osr = osr_sett_to_act_osr[settings->osr_t];
        }
        else
        {
            temp_osr = 16;
        }

        if (settings->osr_p <= 0x05)
        {
            pres_osr = osr_sett_to_act_osr[settings->osr_p];
        }
        else
        {
            pres_osr = 16;
        }

        if (settings->osr_h <= 0x05)
        {
            hum_osr = osr_sett_to_act_osr[settings->osr_h];
        }
        else
        {
            hum_osr = 16;
        }

        (*max_delay) =
            (uint32_t)((1250 + (2300 * temp_osr) +
                        ((2300 * pres_osr) + 575) +
                        ((2300 * hum_osr) + 575)));
    }
    else
    {
        rslt = -1;
    }

    return rslt;
}
# 859 "bme280.c"
static int8_t set_osr_settings(uint8_t desired_settings, const struct bme280_settings *settings, struct bme280_dev *dev)
{
    int8_t rslt = 1;

    if (desired_settings & 1 << 2)
    {
        rslt = set_osr_humidity_settings(settings, dev);
    }

    if (desired_settings & (1 | 1 << 1))
    {
        rslt = set_osr_press_temp_settings(desired_settings, settings, dev);
    }

    return rslt;
}




static int8_t set_osr_humidity_settings(const struct bme280_settings *settings, struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t ctrl_hum;
    uint8_t ctrl_meas;
    uint8_t reg_addr = 0xF2;

    ctrl_hum = settings->osr_h & 0x07;


    rslt = bme280_set_regs(&reg_addr, &ctrl_hum, 1, dev);




    if (rslt == 0)
    {
        reg_addr = 0xF4;
        rslt = bme280_get_regs(reg_addr, &ctrl_meas, 1, dev);

        if (rslt == 0)
        {
            rslt = bme280_set_regs(&reg_addr, &ctrl_meas, 1, dev);
        }
    }

    return rslt;
}





static int8_t set_osr_press_temp_settings(uint8_t desired_settings,
                                          const struct bme280_settings *settings,
                                          struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t reg_addr = 0xF4;
    uint8_t reg_data;

    rslt = bme280_get_regs(reg_addr, &reg_data, 1, dev);

    if (rslt == 0)
    {
        if (desired_settings & 1)
        {
            fill_osr_press_settings(&reg_data, settings);
        }

        if (desired_settings & 1 << 1)
        {
            fill_osr_temp_settings(&reg_data, settings);
        }


        rslt = bme280_set_regs(&reg_addr, &reg_data, 1, dev);
    }

    return rslt;
}





static int8_t set_filter_standby_settings(uint8_t desired_settings,
                                          const struct bme280_settings *settings,
                                          struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t reg_addr = 0xF5;
    uint8_t reg_data;

    rslt = bme280_get_regs(reg_addr, &reg_data, 1, dev);

    if (rslt == 0)
    {
        if (desired_settings & 1 << 3)
        {
            fill_filter_settings(&reg_data, settings);
        }

        if (desired_settings & 1 << 4)
        {
            fill_standby_settings(&reg_data, settings);
        }


        rslt = bme280_set_regs(&reg_addr, &reg_data, 1, dev);
    }

    return rslt;
}





static void fill_filter_settings(uint8_t *reg_data, const struct bme280_settings *settings)
{
    *reg_data = ((*reg_data & ~( 0x1C)) | ((settings->filter << 0x02) & 0x1C));
}





static void fill_standby_settings(uint8_t *reg_data, const struct bme280_settings *settings)
{
    *reg_data = ((*reg_data & ~( 0xE0)) | ((settings->standby_time << 0x05) & 0xE0));
}





static void fill_osr_press_settings(uint8_t *reg_data, const struct bme280_settings *settings)
{
    *reg_data = ((*reg_data & ~( 0x1C)) | ((settings->osr_p << 0x02) & 0x1C));
}





static void fill_osr_temp_settings(uint8_t *reg_data, const struct bme280_settings *settings)
{
    *reg_data = ((*reg_data & ~( 0xE0)) | ((settings->osr_t << 0x05) & 0xE0));
}






static void parse_device_settings(const uint8_t *reg_data, struct bme280_settings *settings)
{
    settings->osr_h = (reg_data[0] & ( 0x07));
    settings->osr_p = ((reg_data[2] & ( 0x1C)) >> ( 0x02));
    settings->osr_t = ((reg_data[2] & ( 0xE0)) >> ( 0x05));
    settings->filter = ((reg_data[3] & ( 0x1C)) >> ( 0x02));
    settings->standby_time = ((reg_data[3] & ( 0xE0)) >> ( 0x05));
}





static void parse_sensor_data(const uint8_t *reg_data, struct bme280_uncomp_data *uncomp_data)
{

    uint32_t data_xlsb;
    uint32_t data_lsb;
    uint32_t data_msb;


    data_msb = (uint32_t)reg_data[0] << 12;
    data_lsb = (uint32_t)reg_data[1] << 4;
    data_xlsb = (uint32_t)reg_data[2] >> 4;
    uncomp_data->pressure = data_msb | data_lsb | data_xlsb;


    data_msb = (uint32_t)reg_data[3] << 12;
    data_lsb = (uint32_t)reg_data[4] << 4;
    data_xlsb = (uint32_t)reg_data[5] >> 4;
    uncomp_data->temperature = data_msb | data_lsb | data_xlsb;


    data_msb = (uint32_t)reg_data[6] << 8;
    data_lsb = (uint32_t)reg_data[7];
    uncomp_data->humidity = data_msb | data_lsb;
}




static int8_t write_power_mode(uint8_t sensor_mode, struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t reg_addr = 0xF4;


    uint8_t sensor_mode_reg_val;


    rslt = bme280_get_regs(reg_addr, &sensor_mode_reg_val, 1, dev);


    if (rslt == 0)
    {
        sensor_mode_reg_val = ((sensor_mode_reg_val & ~( 0x03)) | (sensor_mode & 0x03));


        rslt = bme280_set_regs(&reg_addr, &sensor_mode_reg_val, 1, dev);
    }

    return rslt;
}




static int8_t put_device_to_sleep(struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t reg_data[4];
    struct bme280_settings settings;

    rslt = bme280_get_regs(0xF2, reg_data, 4, dev);

    if (rslt == 0)
    {
        parse_device_settings(reg_data, &settings);
        rslt = bme280_soft_reset(dev);

        if (rslt == 0)
        {
            rslt = reload_device_settings(&settings, dev);
        }
    }

    return rslt;
}





static int8_t reload_device_settings(const struct bme280_settings *settings, struct bme280_dev *dev)
{
    int8_t rslt;

    rslt = set_osr_settings(0x1F, settings, dev);

    if (rslt == 0)
    {
        rslt = set_filter_standby_settings(0x1F, settings, dev);
    }

    return rslt;
}







static double compensate_temperature(const struct bme280_uncomp_data *uncomp_data, struct bme280_calib_data *calib_data)
{
    double var1;
    double var2;
    double temperature;
    double temperature_min = -40;
    double temperature_max = 85;

    var1 = (((double)uncomp_data->temperature) / 16384.0 - ((double)calib_data->dig_t1) / 1024.0);
    var1 = var1 * ((double)calib_data->dig_t2);
    var2 = (((double)uncomp_data->temperature) / 131072.0 - ((double)calib_data->dig_t1) / 8192.0);
    var2 = (var2 * var2) * ((double)calib_data->dig_t3);
    calib_data->t_fine = (int32_t)(var1 + var2);
    temperature = (var1 + var2) / 5120.0;

    if (temperature < temperature_min)
    {
        temperature = temperature_min;
    }
    else if (temperature > temperature_max)
    {
        temperature = temperature_max;
    }

    return temperature;
}





static double compensate_pressure(const struct bme280_uncomp_data *uncomp_data,
                                  const struct bme280_calib_data *calib_data)
{
    double var1;
    double var2;
    double var3;
    double pressure;
    double pressure_min = 30000.0;
    double pressure_max = 110000.0;

    var1 = ((double)calib_data->t_fine / 2.0) - 64000.0;
    var2 = var1 * var1 * ((double)calib_data->dig_p6) / 32768.0;
    var2 = var2 + var1 * ((double)calib_data->dig_p5) * 2.0;
    var2 = (var2 / 4.0) + (((double)calib_data->dig_p4) * 65536.0);
    var3 = ((double)calib_data->dig_p3) * var1 * var1 / 524288.0;
    var1 = (var3 + ((double)calib_data->dig_p2) * var1) / 524288.0;
    var1 = (1.0 + var1 / 32768.0) * ((double)calib_data->dig_p1);


    if (var1 > (0.0))
    {
        pressure = 1048576.0 - (double) uncomp_data->pressure;
        pressure = (pressure - (var2 / 4096.0)) * 6250.0 / var1;
        var1 = ((double)calib_data->dig_p9) * pressure * pressure / 2147483648.0;
        var2 = pressure * ((double)calib_data->dig_p8) / 32768.0;
        pressure = pressure + (var1 + var2 + ((double)calib_data->dig_p7)) / 16.0;

        if (pressure < pressure_min)
        {
            pressure = pressure_min;
        }
        else if (pressure > pressure_max)
        {
            pressure = pressure_max;
        }
    }
    else
    {
        pressure = pressure_min;
    }

    return pressure;
}





static double compensate_humidity(const struct bme280_uncomp_data *uncomp_data,
                                  const struct bme280_calib_data *calib_data)
{
    double humidity;
    double humidity_min = 0.0;
    double humidity_max = 100.0;
    double var1;
    double var2;
    double var3;
    double var4;
    double var5;
    double var6;

    var1 = ((double)calib_data->t_fine) - 76800.0;
    var2 = (((double)calib_data->dig_h4) * 64.0 + (((double)calib_data->dig_h5) / 16384.0) * var1);
    var3 = uncomp_data->humidity - var2;
    var4 = ((double)calib_data->dig_h2) / 65536.0;
    var5 = (1.0 + (((double)calib_data->dig_h3) / 67108864.0) * var1);
    var6 = 1.0 + (((double)calib_data->dig_h6) / 67108864.0) * var1 * var5;
    var6 = var3 * var4 * (var5 * var6);
    humidity = var6 * (1.0 - ((double)calib_data->dig_h1) * var6 / 524288.0);

    if (humidity > humidity_max)
    {
        humidity = humidity_max;
    }
    else if (humidity < humidity_min)
    {
        humidity = humidity_min;
    }

    return humidity;
}
# 1434 "bme280.c"
static int8_t get_calib_data(struct bme280_dev *dev)
{
    int8_t rslt;
    uint8_t reg_addr = 0x88;


    uint8_t calib_data[26] = { 0 };


    rslt = bme280_get_regs(reg_addr, calib_data, 26, dev);

    if (rslt == 0)
    {



        parse_temp_press_calib_data(calib_data, dev);
        reg_addr = 0xE1;


        rslt = bme280_get_regs(reg_addr, calib_data, 7, dev);

        if (rslt == 0)
        {



            parse_humidity_calib_data(calib_data, dev);
        }
    }

    return rslt;
}





static void interleave_reg_addr(const uint8_t *reg_addr, uint8_t *temp_buff, const uint8_t *reg_data, uint32_t len)
{
    uint32_t index;

    for (index = 1; index < len; index++)
    {
        temp_buff[(index * 2) - 1] = reg_addr[index];
        temp_buff[index * 2] = reg_data[index];
    }
}





static void parse_temp_press_calib_data(const uint8_t *reg_data, struct bme280_dev *dev)
{
    struct bme280_calib_data *calib_data = &dev->calib_data;

    calib_data->dig_t1 = (((uint16_t)reg_data[1] << 8) | (uint16_t)reg_data[0]);
    calib_data->dig_t2 = (int16_t)(((uint16_t)reg_data[3] << 8) | (uint16_t)reg_data[2]);
    calib_data->dig_t3 = (int16_t)(((uint16_t)reg_data[5] << 8) | (uint16_t)reg_data[4]);
    calib_data->dig_p1 = (((uint16_t)reg_data[7] << 8) | (uint16_t)reg_data[6]);
    calib_data->dig_p2 = (int16_t)(((uint16_t)reg_data[9] << 8) | (uint16_t)reg_data[8]);
    calib_data->dig_p3 = (int16_t)(((uint16_t)reg_data[11] << 8) | (uint16_t)reg_data[10]);
    calib_data->dig_p4 = (int16_t)(((uint16_t)reg_data[13] << 8) | (uint16_t)reg_data[12]);
    calib_data->dig_p5 = (int16_t)(((uint16_t)reg_data[15] << 8) | (uint16_t)reg_data[14]);
    calib_data->dig_p6 = (int16_t)(((uint16_t)reg_data[17] << 8) | (uint16_t)reg_data[16]);
    calib_data->dig_p7 = (int16_t)(((uint16_t)reg_data[19] << 8) | (uint16_t)reg_data[18]);
    calib_data->dig_p8 = (int16_t)(((uint16_t)reg_data[21] << 8) | (uint16_t)reg_data[20]);
    calib_data->dig_p9 = (int16_t)(((uint16_t)reg_data[23] << 8) | (uint16_t)reg_data[22]);
    calib_data->dig_h1 = reg_data[25];
}





static void parse_humidity_calib_data(const uint8_t *reg_data, struct bme280_dev *dev)
{
    struct bme280_calib_data *calib_data = &dev->calib_data;
    int16_t dig_h4_lsb;
    int16_t dig_h4_msb;
    int16_t dig_h5_lsb;
    int16_t dig_h5_msb;

    calib_data->dig_h2 = (int16_t)(((uint16_t)reg_data[1] << 8) | (uint16_t)reg_data[0]);
    calib_data->dig_h3 = reg_data[2];
    dig_h4_msb = (int16_t)(int8_t)reg_data[3] * 16;
    dig_h4_lsb = (int16_t)(reg_data[4] & 0x0F);
    calib_data->dig_h4 = dig_h4_msb | dig_h4_lsb;
    dig_h5_msb = (int16_t)(int8_t)reg_data[5] * 16;
    dig_h5_lsb = (int16_t)(reg_data[4] >> 4);
    calib_data->dig_h5 = dig_h5_msb | dig_h5_lsb;
    calib_data->dig_h6 = (int8_t)reg_data[6];
}





static uint8_t are_settings_changed(uint8_t sub_settings, uint8_t desired_settings)
{
    uint8_t settings_changed = 0;

    if (sub_settings & desired_settings)
    {

        settings_changed = 1;
    }
    else
    {

        settings_changed = 0;
    }

    return settings_changed;
}





static int8_t null_ptr_check(const struct bme280_dev *dev)
{
    int8_t rslt;

    if ((dev == ((void*)0)) || (dev->read == ((void*)0)) || (dev->write == ((void*)0)) || (dev->delay_us == ((void*)0)))
    {

        rslt = -1;
    }
    else
    {

        rslt = 0;
    }

    return rslt;
}
