// interface_pcf8574A.h
// 
// interface for the mcp23008 general io expander
// this specific driver defines functions to put the chip's IOs into readonly inputs.
// creator: John-William Lebel
// date: 2020-10-08

#ifndef INTERFACE_PCF8574A_H
#define INTERFACE_PCF8574A_H

/* put this in main.h if you're using it and it's not there
#define PCF8574A_CHIP_ADDRESS 0x7A
*/

void interface_pcf8574A_init();
unsigned char interface_pcf8574A_readInputByte(unsigned char chipAddress);
void interface_pcf8574A_writeOutputByte(unsigned char chipAddress, unsigned char outputByte);

#endif