// service_applicationInputHandler.h
// 
// creator: John-William Lebel
// date: 2020-10-08

#ifndef SERVICE_APPLICATIONINPUTHANDLER_H
#define SERVICE_APPLICATIONINPUTHANDLER_H

/* put this in main.h if you're using it and it's not there
#define PCF8574A_CHIP_ADDRESS 0x7A
*/

typedef struct {
    // 7 bits
    unsigned long poussoirMagasinBlocPositionEntree: 1,
    poussoirMagasinBlocPositionSortie: 1,
    detecteurOptiqueTypeBloc: 1,
    detecteurOptiqueBlocChute: 1,
    boutonDepart: 1,
    boutonArret: 1,
    indicationPressionVentouse: 1,
    
    // 8 bits
    cylindreVentouseHaut: 1,
    cylindreVentouseBas: 1,
    detecteurMagnetiqueTypeBloc: 1,
    detecteurCapacitifTypeBloc: 1,
    ejecteurBlocPositionEntree: 1,
    ejecteurBlocPositionSortie: 1,
    elevateurBas: 1,
    elevateurHaut: 1,
    
    // 4 bits
    isReadyForOperation: 1,
    isDefaultMotionComplete: 1,
    isDefaultAckStart: 1,
    hasDefaultError: 1,
    
    // 1 bit
    passageParZero: 1,
    
    // 8 bits
    detecteurHauteurBloc: 8,
    
    // unused bits
    vide: 5;
} service_applicationInputHandler_Data;

service_applicationInputHandler_Data service_applicationInputHandler_data;

void service_applicationInputHandler_init();
void service_applicationInputHandler_update();

#endif