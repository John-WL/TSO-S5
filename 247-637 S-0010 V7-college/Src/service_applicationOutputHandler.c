// service_applicationOutputHandler.c
// 
// creator: John-William Lebel et Philippe Lemoine
// date: 2020-11-18

#include "service_applicationOutputHandler.h"
#include "main.h"
#include "service_bitOperation.h"
#include "interface_pcf8574A.h"
#include "interface_mcp3021.h"
#include "interface_lightColumn.h"
#include "interface_stepperMotor.h"
#include "interface_triac.h"

unsigned char valueOfOutputBoard0;
unsigned char valueOfOutputBoard1;
unsigned char valueOfLightColumn;
unsigned char stepMotorState;
unsigned char triacState;

// data struct
extern service_applicationOutputHandler_Data service_applicationOutputHandler_data;

// public function
void service_applicationOutputHandler_init() {
    valueOfOutputBoard0 = 0;
    valueOfOutputBoard1 = 0;
    valueOfLightColumn = 0;
    stepMotorState = 0;
    triacState = 0;
}

void service_applicationOutputHandler_update() {
    // map the output data class to the output ports and pins
    // board 0
    service_bitOperation_setBit(&valueOfOutputBoard0, service_applicationOutputHandler_data.lumierePanneauAvant, 0);
    service_bitOperation_setBit(&valueOfOutputBoard0, service_applicationOutputHandler_data.cylindreVentouseBas, 1);
    service_bitOperation_setBit(&valueOfOutputBoard0, service_applicationOutputHandler_data.cylindreVentouseHaut, 2);
    service_bitOperation_setBit(&valueOfOutputBoard0, service_applicationOutputHandler_data.vacuumOnSolenoide, 3);
    service_bitOperation_setBit(&valueOfOutputBoard0, service_applicationOutputHandler_data.elevateurPositionBasse, 4);
    service_bitOperation_setBit(&valueOfOutputBoard0, service_applicationOutputHandler_data.elevateurPositionHaute, 5);
    service_bitOperation_setBit(&valueOfOutputBoard0, service_applicationOutputHandler_data.poussoirMagasinBlocEntree, 6);
    service_bitOperation_setBit(&valueOfOutputBoard0, service_applicationOutputHandler_data.poussoirMagasinBlocSortie, 7);
    
    // board 1
    service_bitOperation_setBit(&valueOfOutputBoard1, service_applicationOutputHandler_data.ejecteurBlocPositionSortie, 0);
    service_bitOperation_setBit(&valueOfOutputBoard1, service_applicationOutputHandler_data.relaisConvoyeur, 1);
    service_bitOperation_setBit(&valueOfOutputBoard1, service_applicationOutputHandler_data.selectionPosition0, 2);
    service_bitOperation_setBit(&valueOfOutputBoard1, service_applicationOutputHandler_data.selectionPosition1, 3);
    service_bitOperation_setBit(&valueOfOutputBoard1, service_applicationOutputHandler_data.selectionPosition2, 4);
    service_bitOperation_setBit(&valueOfOutputBoard1, service_applicationOutputHandler_data.isEndStageEnabled, 5);
    service_bitOperation_setBit(&valueOfOutputBoard1, service_applicationOutputHandler_data.hasPositionProcessStarted, 6);
    
    // light column
    service_bitOperation_setBit(&valueOfLightColumn, service_applicationOutputHandler_data.greenLightInColumn, 0);
    service_bitOperation_setBit(&valueOfLightColumn, service_applicationOutputHandler_data.yellowLightInColumn, 1);
    service_bitOperation_setBit(&valueOfLightColumn, service_applicationOutputHandler_data.redLightInColumn, 2);
    
    // stepper motor
    service_bitOperation_setBit(&stepMotorState, service_applicationOutputHandler_data.stepMotorA1, 0);
    service_bitOperation_setBit(&stepMotorState, service_applicationOutputHandler_data.stepMotorA2, 1);
    service_bitOperation_setBit(&stepMotorState, service_applicationOutputHandler_data.stepMotorB1, 2);
    service_bitOperation_setBit(&stepMotorState, service_applicationOutputHandler_data.stepMotorB2, 3);
    
    // triac
    service_bitOperation_setBit(&triacState, service_applicationOutputHandler_data.triac, 0);
    
    // use the i2c bus to send the data to the output borads
    interface_pcf8574A_writeOutputByte(PCF8574A_CHIP_ADDRESS_0, valueOfOutputBoard0);
    interface_pcf8574A_writeOutputByte(PCF8574A_CHIP_ADDRESS_1, valueOfOutputBoard1);
    
    // set other output pin states
    interface_lightColumn_writeOutputByte(valueOfLightColumn);
    interface_stepperMotor_writeOutputByte(stepMotorState);
    interface_triac_writeTriacValue(triacState);
    
    // please refer to the connection table and schematic in the documentation for further info on physical connections
}
