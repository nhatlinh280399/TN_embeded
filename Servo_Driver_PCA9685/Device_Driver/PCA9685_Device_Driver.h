#ifndef _SERVO_H_
#define _SERVO_H_

#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/delay.h>
#include <linux/kernel.h>

#define I2C_BUS_AVAILABLE   (          1 )              // I2C Bus available in our Raspberry Pi
#define SLAVE_DEVICE_NAME   ( "PCA9685" )               // Ten cua Device va Driver
#define PCA9685_SLAVE_ADDR  (       0x40 )  			// Slave Address


//Register definitions (xem trong datasheet PCA9685)

#define SUBADR1          0x02
#define SUBADR2          0x03
#define SUBADR3          0x04
#define MODE1            0x00
#define MODE2            0x01
#define PRESCALE         0xFE
#define LED0_ON_L        0x06
#define LED0_ON_H        0x07
#define LED0_OFF_L       0x08
#define LED0_OFF_H       0x09
#define ALLLED_ON_L      0xFA
#define ALLLED_ON_H      0xFB
#define ALLLED_OFF_L     0xFC
#define ALLLED_OFF_H     0xFD

#define PWM_I2C_Addr 	 0x40
#define PWM_I2C_Hz 	 	 50

static void PCA9685_setPWM(uint8_t channel, uint16_t on, uint16_t off);
static void PCA9685_setServoPulse(uint8_t channel, uint16_t value);

#endif