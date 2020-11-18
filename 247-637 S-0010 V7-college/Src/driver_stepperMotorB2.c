// driver_stepperMotorB2.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "driver_stepperMotorB2.h"
#include "main.h"

void driver_stepperMotorB2_init() {
    HAL_GPIO_WritePin(stepMotorB2_GPIO_Port, stepMotorB2_Pin, GPIO_PIN_RESET);
}

void driver_stepperMotorB2_set(unsigned char outputBit) {
    HAL_GPIO_WritePin(stepMotorB2_GPIO_Port, stepMotorB2_Pin, (GPIO_PinState) outputBit);
}
