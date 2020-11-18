// service_bitOperation.h
// 
// creator: John-William Lebel
// date: 2020-11-18

#ifndef SERVICE_BITOPERATION_H
#define SERVICE_BITOPERATION_H

unsigned char service_bitOperation_isolateBit(unsigned char sensorData, unsigned char bitToIsolate);
void service_bitOperation_setBit(unsigned char* byteToSet, unsigned char bitValue, unsigned char bitSelector);

#endif