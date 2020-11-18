// interface_mcp3021.h
// 
// interface for the max11601 adc
// creator: John-William Lebel
// date: 2020-10-08

#ifndef INTERFACE_MCP3021_H
#define INTERFACE_MCP3021_H

/* put this in main.h if you're using it and it's not there
#define MCP3021_CHIP_ADDRESS 0xc8
#define ADC_BYTE_TO_VOLTS_FACTOR 0.01953125
*/

void interface_mcp3021_init();
unsigned char interface_mcp3021_readInputByte();

#endif