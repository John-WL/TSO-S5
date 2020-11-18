// driver_stepperMotorB1.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "driver_stepperMotorB1.h"
#include "main.h"

void driver_stepperMotorB1_init() {
    HAL_GPIO_WritePin(stepMotorB1_GPIO_Port, stepMotorB1_Pin, GPIO_PIN_RESET);
}

void driver_stepperMotorB1_set(unsigned char outputBit) {
    HAL_GPIO_WritePin(stepMotorB1_GPIO_Port, stepMotorB1_Pin, (GPIO_PinState) outputBit);
}

