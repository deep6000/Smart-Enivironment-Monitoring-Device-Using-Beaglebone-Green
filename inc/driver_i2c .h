/*
@File Name	: myI2C.h
@Description: I2C file Wrapper function  
@Author		: Deepesh Sonigra 
@Author		: Madhumitha Tolakanahalli
@Date		: 03/17/2019
@citation	: https://elinux.org/Interfacing_with_I2C_Devices
*/


#include<stdio.h>
#include<conio.h>
#include<stdint.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>
#include<errno.h>
#include<fctnl.h>
#include<linux/i2c-dev.h>
#include<sys/ioctl.h>
#include<sys/stat.h>

#define ADAPTER_NUM (2)

/**************************************************************************************
@Function 	: int8_t open_i2c_bus()
@Description: Opens i2c bus 
@Return Type: int8_t new file descriptor(success), -1(failure)
*************************************************************************************/
int8_t open_i2c_bus();

/**************************************************************************************
@Function 	: void close_i2c_bus()
@Description: close i2c bus 
@Return Type: 1 (success), -1(failure)
*************************************************************************************/
void close_i2c_bus