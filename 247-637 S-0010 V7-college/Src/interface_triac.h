// interface_triac.h
// 
// creator: John-William Lebel
// date: 2020-10-08

#ifndef INTERFACE_TRIAC_H
#define INTERFACE_TRIAC_H

void interface_triac_init();
void interface_triac_writeTriacValue(unsigned char triacValue);
unsigned char interface_triac_isPassingByZero();

#endif