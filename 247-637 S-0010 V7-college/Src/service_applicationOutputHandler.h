// service_applicationOutputHandler.h
// 
// interface for the mcp23008 general io expander
// this specific driver defines functions to put the chip's IOs into readonly inputs.
// creator: John-William Lebel
// date: 2020-10-08

#ifndef SERVICE_APPLICATIONOUTPUTHANDLER_H
#define SERVICE_APPLICATIONOUTPUTHANDLER_H

/* put this in main.h if you're using it and it's not there
#define PCF8574A_CHIP_ADDRESS 0x7A
*/

typedef struct {
    // 8 bits
    unsigned long lumierePanneauAvant: 1,
    cylindreVentouseBas: 1,
    cylindreVentouseHaut: 1,
    vacuumOnSolenoide: 1,
    elevateurPositionBasse: 1,
    elevateurPositionHaute: 1,
    poussoirMagasinBlocEntree: 1,
    poussoirMagasinBlocSortie: 1,
    
    // 7 bits
    ejecteurBlocPositionSortie: 1,
    relaisConvoyeur: 1,
    selectionPosition0: 1,
    selectionPosition1: 1,
    selectionPosition2: 1,
    isEndStageEnabled: 1,
    hasPositionProcessStarted: 1,
    
    // 3 bits
    greenLightInColumn: 1,
    yellowLightInColumn: 1,
    redLightInColumn: 1,
    
    // 4 bits
    stepMotorA1: 1,
    stepMotorA2: 1,
    stepMotorB1: 1,
    stepMotorB2: 1,
    
    // 1 bit
    triac: 1,
    
    // 10 bit
    vide: 9;
    
} service_applicationOutputHandler_Data;

service_applicationOutputHandler_Data service_applicationOutputHandler_data;

void service_applicationOutputHandler_init();
void service_applicationOutputHandler_update();

#endif