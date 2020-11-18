// driver_i2c.h
// 
// driver for i2c communication on the stm32
// creator: John-William Lebel
// date: 2020-10-08
// modification: 2020-11-18

#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

void driver_i2c_writeByte(unsigned char deviceAddress, unsigned char registerToWriteTo, unsigned char byteToSend);
void driver_i2c_writeByteNoRegister(unsigned char deviceAddress, unsigned char byteToSend);
unsigned char driver_i2c_readByteAtAddress(unsigned char deviceAddress, unsigned char registerToReadFrom);
unsigned char driver_i2c_readByte(unsigned char deviceAddress);
unsigned char* driver_i2c_readByteArray(unsigned char deviceAddress, unsigned char arrayLength);

#endif