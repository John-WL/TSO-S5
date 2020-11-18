// interface_stepperMotor.c
// 
// creator: John-William Lebel
// date: 2020-10-08

#include "interface_stepperMotor.h"
#include "main.h"
#include "driver_stepperMotorA1.h"
#include "driver_stepperMotorA2.h"
#include "driver_stepperMotorB1.h"
#include "driver_stepperMotorB2.h"

void interface_stepperMotor_init() {
   driver_stepperMotorA1_set(0);
   driver_stepperMotorA2_set(0);
   driver_stepperMotorB1_set(0);
   driver_stepperMotorB2_set(0);
}

void interface_stepperMotor_writeOutputByte(unsigned char byteValue) {
   driver_stepperMotorA1_set(byteValue & 0x01);
   driver_stepperMotorA2_set((byteValue >> 1) & 0x01);
   driver_stepperMotorB1_set((byteValue >> 2) & 0x01);
   driver_stepperMotorB2_set((byteValue >> 3) & 0x01);
}
