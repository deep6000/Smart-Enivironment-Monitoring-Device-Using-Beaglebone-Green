/*
@File Name	: myI2C.h
@Description: I2C file Wrapper function  
@Author		: Deepesh Sonigra 
@Author		: Madhumitha Tolakanahalli
@Date		: 03/17/2019
@citation	: https://elinux.org/Interfacing_with_I2C_Devices
*/

#include "driver_i2c.h"


#define TMP102_SLAVE_ADDR 		(0x48)

/* Register Address */
enum TMP102_REG
{
	TMP_REG_TEMPERATURE =   (0x00),
	TMP_REG_CONFIGURATION =	(0x01),
	TMP_REG_TLOW =			(0x02),
	TMP_REG_THIGH = 		(0x03)
};

enum TMP_CONFIG_MODES
{
	
}