// driver_passingByZero.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "driver_passingByZero.h"
#include "main.h"

void driver_passingByZero_init() {}

unsigned char driver_passingByZero_read() {
    return HAL_GPIO_ReadPin(passageParZero_GPIO_Port, passageParZero_Pin);
}

