// interface_pcf8574A.c
// 
// interface for the mcp23008 general io expander
// this specific driver defines functions to put the chip's IOs into readonly inputs.
// creator: John-William Lebel
// date: 2020-10-08

#include "interface_pcf8574A.h"
#include "main.h"
#include "driver_i2c.h"

void interface_pcf8574A_init() {
    // init IODIR
}

unsigned char interface_pcf8574A_readInputByte(unsigned char chipAddress) {
    // read GPIO
    return driver_i2c_readByte(chipAddress);
}

void interface_pcf8574A_writeOutputByte(unsigned char chipAddress, unsigned char outputByte) {
    // write GPIO
    driver_i2c_writeByteNoRegister(chipAddress, outputByte);
}
