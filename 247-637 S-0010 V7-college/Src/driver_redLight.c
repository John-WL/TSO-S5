// driver_redLight.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "driver_redLight.h"
#include "main.h"

void driver_redLight_init() {
    HAL_GPIO_WritePin(redLightInColumn_GPIO_Port, redLightInColumn_Pin, GPIO_PIN_RESET);
}

void driver_redLight_set(unsigned char outputBit) {
    HAL_GPIO_WritePin(redLightInColumn_GPIO_Port, redLightInColumn_Pin, (GPIO_PinState) outputBit);
}

