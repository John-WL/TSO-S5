// interface_lightColumn.c
// 
// creator: John-William Lebel
// date: 2020-10-08

#include "interface_lightColumn.h"
#include "main.h"
#include "driver_greenLight.h"
#include "driver_yellowLight.h"
#include "driver_redLight.h"

void interface_lightColumn_init() {
    driver_greenLight_init();
    driver_yellowLight_init();
    driver_redLight_init();
}

void interface_lightColumn_writeOutputByte(unsigned char outputBit) {
    driver_greenLight_set(outputBit & 0x01);
    driver_yellowLight_set((outputBit >> 1) & 0x01);
    driver_redLight_set((outputBit >> 2) & 0x01);
}

