// interface_mcp3021.c
// 
// interface for the max11601 adc
// creator: John-William Lebel
// date: 2020-10-08

#include "interface_mcp3021.h"
#include "main.h"
#include "driver_i2c.h"

void interface_mcp3021_init() {
    // everything already setup to use
}

unsigned char interface_mcp3021_readInputByte() {
    // read the adc
    const unsigned char* value = driver_i2c_readByteArray(MCP3021_CHIP_ADDRESS, 2);
    return (value[0] << 4) | (value[1] >> 4);
}
