// service_applicationInputHandler.c
// 
// creator: John-William Lebel et Philippe Lemoine
// date: 2020-11-18

#include "service_applicationlnputHandler.h"
#include "main.h"
#include "service_bitOperation.h"
#include "interface_pcf8574A.h"
#include "interface_mcp3021.h"
#include "interface_triac.h"

unsigned char valueOfInputBoard0;
unsigned char valueOfInputBoard1;
unsigned char valueOfInputBoard2;
unsigned char valueOfPassageParZero;
unsigned char valueOfAdc;

extern service_applicationInputHandler_Data service_applicationInputHandler_data;

void service_applicationInputHandler_init() {
    valueOfInputBoard0 = 0;
    valueOfInputBoard1 = 0;
    valueOfInputBoard2 = 0;
    valueOfPassageParZero = 0;
    valueOfAdc = 0;
}

void service_applicationInputHandler_update() {
    // use the i2c bus to get the data form the input borads
    valueOfInputBoard0 = interface_pcf8574A_readInputByte(PCF8574A_CHIP_ADDRESS_2);
    valueOfInputBoard1 = interface_pcf8574A_readInputByte(PCF8574A_CHIP_ADDRESS_3);
    valueOfInputBoard2 = interface_pcf8574A_readInputByte(PCF8574A_CHIP_ADDRESS_4);
    valueOfPassageParZero = interface_triac_isPassingByZero();
    valueOfAdc = interface_mcp3021_readInputByte();
    
    // map the inputs to the data class
    // input board 0
    service_applicationInputHandler_data.poussoirMagasinBlocPositionEntree = service_bitOperation_isolateBit(valueOfInputBoard0, 0);
    service_applicationInputHandler_data.poussoirMagasinBlocPositionSortie = service_bitOperation_isolateBit(valueOfInputBoard0, 1);
    service_applicationInputHandler_data.detecteurOptiqueTypeBloc = service_bitOperation_isolateBit(valueOfInputBoard0, 2);
    service_applicationInputHandler_data.detecteurOptiqueBlocChute = service_bitOperation_isolateBit(valueOfInputBoard0, 3);
    service_applicationInputHandler_data.boutonDepart = service_bitOperation_isolateBit(valueOfInputBoard0, 4);
    service_applicationInputHandler_data.boutonArret = service_bitOperation_isolateBit(valueOfInputBoard0, 5);
    service_applicationInputHandler_data.indicationPressionVentouse = service_bitOperation_isolateBit(valueOfInputBoard0, 6);
    
    // input board 1
    service_applicationInputHandler_data.cylindreVentouseHaut = service_bitOperation_isolateBit(valueOfInputBoard1, 0);
    service_applicationInputHandler_data.cylindreVentouseBas = service_bitOperation_isolateBit(valueOfInputBoard1, 1);
    service_applicationInputHandler_data.detecteurMagnetiqueTypeBloc = service_bitOperation_isolateBit(valueOfInputBoard1, 2);
    service_applicationInputHandler_data.detecteurCapacitifTypeBloc = service_bitOperation_isolateBit(valueOfInputBoard1, 3);
    service_applicationInputHandler_data.ejecteurBlocPositionEntree = service_bitOperation_isolateBit(valueOfInputBoard1, 4);
    service_applicationInputHandler_data.ejecteurBlocPositionSortie = service_bitOperation_isolateBit(valueOfInputBoard1, 5);
    service_applicationInputHandler_data.elevateurBas = service_bitOperation_isolateBit(valueOfInputBoard1, 6);
    service_applicationInputHandler_data.elevateurHaut = service_bitOperation_isolateBit(valueOfInputBoard1, 7);
    
    // input board 2
    service_applicationInputHandler_data.isReadyForOperation = service_bitOperation_isolateBit(valueOfInputBoard2, 0);
    service_applicationInputHandler_data.isDefaultMotionComplete = service_bitOperation_isolateBit(valueOfInputBoard2, 1);
    service_applicationInputHandler_data.isDefaultAckStart = service_bitOperation_isolateBit(valueOfInputBoard2, 2);
    service_applicationInputHandler_data.hasDefaultError = service_bitOperation_isolateBit(valueOfInputBoard2, 3);
    
    // passage par zero for triac use
    service_applicationInputHandler_data.passageParZero = service_bitOperation_isolateBit(valueOfPassageParZero, 0);
    
    // adc value
    service_applicationInputHandler_data.detecteurHauteurBloc = valueOfAdc;
    
    // please refer to the connection table and schematic in the documentation for further info on physical connections
}
