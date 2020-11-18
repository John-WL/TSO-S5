// service_bitOperation.c
// 
// creator: John-William Lebel
// date: 2020-11-18

#include "service_bitOperation.h"
#include "main.h"

unsigned char service_bitOperation_isolateBit(unsigned char sensorData, unsigned char bitToIsolate) {
    return (sensorData >> bitToIsolate) & 0x01;
}

void service_bitOperation_setBit(unsigned char* byteToSet, unsigned char bitValue, unsigned char bitSelector) {
  if(bitValue) {
      *byteToSet |= 1 << bitSelector;
  }
  else {
      *byteToSet &= ~(1 << bitSelector);
  }
}