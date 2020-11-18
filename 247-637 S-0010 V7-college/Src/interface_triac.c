// interface_triac.c
// 
// creator: John-William Lebel
// date: 2020-10-08

#include "interface_triac.h"
#include "main.h"
#include "driver_triac.h"
#include "driver_passingByZero.h"

void interface_triac_init() {
    driver_triac_init();
    driver_passingByZero_init();
}

void interface_triac_writeTriacValue(unsigned char triacValue) {
    driver_triac_write(triacValue);
}

unsigned char interface_triac_isPassingByZero() {
    return driver_passingByZero_read();
}
