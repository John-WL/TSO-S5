// driver_greenLight.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "driver_greenLight.h"
#include "main.h"

void driver_greenLight_init() {
    HAL_GPIO_WritePin(greenLightInColumn_GPIO_Port, greenLightInColumn_Pin, GPIO_PIN_RESET);
}

void driver_greenLight_set(unsigned char outputBit) {
    HAL_GPIO_WritePin(greenLightInColumn_GPIO_Port, greenLightInColumn_Pin, (GPIO_PinState) outputBit);
}

