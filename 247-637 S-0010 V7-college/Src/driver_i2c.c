// driver_i2c.c
// 
// driver for i2c communication on the stm32
// creator: John-William Lebel
// date: 2020-10-08
// modifications: 2020-11-18

#include "driver_i2c.h"
#include "main.h"
#include "stm32f4xx_hal_i2c.h"

extern I2C_HandleTypeDef hi2c1;
unsigned char data[2] = {0, 0};
unsigned char receivedByte[2] = {0, 0};

void driver_i2c_writeByte(unsigned char deviceAddress, unsigned char registerToWriteTo, unsigned char byteToSend) {
    data[0] = registerToWriteTo;
    data[1] = byteToSend;
    HAL_I2C_Master_Transmit(&hi2c1, deviceAddress & ~0x01, data, 2, HAL_MAX_DELAY);
}

void driver_i2c_writeByteNoRegister(unsigned char deviceAddress, unsigned char byteToSend) {
    data[0] = byteToSend;
    HAL_I2C_Master_Transmit(&hi2c1, deviceAddress & ~0x01, data, 1, HAL_MAX_DELAY);
}

unsigned char driver_i2c_readByteAtAddress(unsigned char deviceAddress, unsigned char registerToReadFrom) {
    data[0] = registerToReadFrom;
    HAL_I2C_Master_Transmit(&hi2c1, deviceAddress, data, 1, HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(&hi2c1, deviceAddress | 0x01, receivedByte, 1, HAL_MAX_DELAY);
    
    return receivedByte[0];
}

unsigned char driver_i2c_readByte(unsigned char deviceAddress) {
    HAL_I2C_Master_Receive(&hi2c1, deviceAddress | 0x01, receivedByte, 1, HAL_MAX_DELAY);
    
    return receivedByte[0];
}

unsigned char* driver_i2c_readByteArray(unsigned char deviceAddress, unsigned char arrayLength) {
    HAL_I2C_Master_Receive(&hi2c1, deviceAddress | 0x01, receivedByte, arrayLength, HAL_MAX_DELAY);
    
    return receivedByte;
}