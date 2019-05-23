#ifndef GLOBALS_H
#define GLOBALS_H

#include "Arduino.h"
#include "bool.h"

#define TASK_NUMBER 7

typedef enum {NONE, TEMP, BLOOD, PULSE} selection;
selection measureSelection;
selection acknowledge;
typedef enum {MENU, ANNUNCIATION} mode;
mode modeSelecton;

// TCB struct
typedef enum {PIRORITY_REAL_TIME,PRIORITY_HIGH,PRIORITY_LOW} TaskPriority;
typedef struct TCB {
    void (*taskPtr)(void*);
    void* taskDataPtr;
    TaskPriority priority;
    struct TCB* prev;
    struct TCB* next;
}TCB;

typedef struct TCB_linkedList {
    TCB* head;
    TCB* tail;
} TCB_linkedList;

void deleteTask(TCB* node, TCB_linkedList linkedList);
void insertTask(TCB* node, TCB_linkedList linkedList);

TCB_linkedList linkedListTCB;
TCB_linkedList linkedListData;
TCB taskQueue[TASK_NUMBER];
TCB taskQueueData[TASK_NUMBER];

// Measurement struct
typedef struct MeasureSubsystemDataStruct {
    unsigned int* temperatureRawBuf;
    unsigned int* bloocPressRawBuf;
    unsigned int* pulseRateRawBuf;
    selection* measurementSelectionPtr;
} MeasureSubsystemData;

// Compute Struct
typedef struct ComputeSubsystemData{
    unsigned int* temperatureRawBuf;
    unsigned int* bloodPressRawBuf;
    unsigned int* pulseRateRawBuf;

    unsigned char* temperatureCorrectedBuf;
    unsigned char* bloodPressCorrectedBuf;
    unsigned char* pulseRateCorrectedBuf;

    selection* measurementSelectionPtr;
} ComputeSubsystemData;

// Display Struct
typedef struct DisplayData {
    unsigned char* temperatureCorrectedBuff;
    unsigned char* bloodPressCorrectedBuf;
    unsigned char* pulseRateCorrectedBuf;
    unsigned short* batteryState;
} DisplaySubsystemData;

// Warning Struct
typedef struct WarningAlarmData {
    unsigned int* temperatureRawBuf;
    unsigned int* bloodPressRawBuf;
    unsigned int* pulseRateRawBuf;
    unsigned short* batteryState;
} WarningAlarmSubsystemData;

// Status Struct
typedef struct StatusData{
    unsigned short* batteryState;
} StatusSubsystemData;

// KeyPad Struct
typedef struct KeyPadData {
    selection* measurementSelection;
    selection* alarmAcknowledge;
} KeyPadData;

// Communication Struct
typedef struct CommunicationsData {
    unsigned char* temperatureCorrectedBuf;
    unsigned char* bloodPressCorrectedBuf;
    unsigned char* pulseRateCorrectedBuf;
} CommunicationsData;



// Measurements Data
unsigned int temperatureRawBuf[8];
unsigned int bloodPressRawBuf[16];
unsigned int pulseRateRawBuf[8];     
unsigned char temperatureCorrectedBuf[8];
unsigned char bloodPressCorrectedBuf[16];
unsigned char pulseRateCorrectedBuf[8];
        
// Buffer Index
unsigned int tempRawIndex, bpRawIndex, prRawIndex, tempCorrectIndex, bpCorrectedIndex, prCorrectedIndex;

//TFT Keypad
unsigned short functionSelect;
unsigned short measurementSelection;
unsigned short alarmAcknowledge;

//Status 
unsigned short batteryState;

//Alarms
unsigned char bpOutOfRange;
unsigned char tempOutOfRange;
unsigned char pulseOutOfRange;

// Warning
Bool bpHigh;
Bool tempHigh;
Bool pulseLow;

// static allocation to struct
MeasureSubsystemData measureData;
ComputeSubsystemData computeData;
DisplaySubsystemData displayData;
WarningAlarmSubsystemData warningAlarmData;
StatusSubsystemData statusData;
KeyPadData keyData;

void init();

#endif // GLOBALS_H
