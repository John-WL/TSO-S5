// driver_stepperMotorA1.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "driver_stepperMotorA1.h"
#include "main.h"

void driver_stepperMotorA1_init() {
    HAL_GPIO_WritePin(stepMotorA1_GPIO_Port, stepMotorA1_Pin, GPIO_PIN_RESET);
}

void driver_stepperMotorA1_set(unsigned char outputBit) {
    HAL_GPIO_WritePin(stepMotorA1_GPIO_Port, stepMotorA1_Pin, (GPIO_PinState) outputBit);
}

