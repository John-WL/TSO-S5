// driver_yellowLight.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "driver_yellowLight.h"
#include "main.h"

void driver_yellowLight_init() {
    HAL_GPIO_WritePin(yellowLightInColumn_GPIO_Port, yellowLightInColumn_Pin, GPIO_PIN_RESET);
}

void driver_yellowLight_set(unsigned char outputBit) {
    HAL_GPIO_WritePin(yellowLightInColumn_GPIO_Port, yellowLightInColumn_Pin, (GPIO_PinState) outputBit);
}

