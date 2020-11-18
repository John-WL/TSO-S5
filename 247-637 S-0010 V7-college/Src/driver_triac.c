// driver_triac.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "driver_triac.h"
#include "main.h"

void driver_triac_init() {
    HAL_GPIO_WritePin(triac_GPIO_Port, triac_Pin, GPIO_PIN_RESET);
}

void driver_triac_write(unsigned char outputBit) {
    HAL_GPIO_WritePin(triac_GPIO_Port, triac_Pin, (GPIO_PinState) outputBit);
}

