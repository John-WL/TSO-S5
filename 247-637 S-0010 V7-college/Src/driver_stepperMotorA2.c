// driver_stepperMotorA2.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "driver_stepperMotorA2.h"
#include "main.h"

void driver_stepperMotorA2_init() {
    HAL_GPIO_WritePin(stepMotorA2_GPIO_Port, stepMotorA2_Pin, GPIO_PIN_RESET);
}

void driver_stepperMotorA2_set(unsigned char outputBit) {
    HAL_GPIO_WritePin(stepMotorA2_GPIO_Port, stepMotorA2_Pin, (GPIO_PinState) outputBit);
}

