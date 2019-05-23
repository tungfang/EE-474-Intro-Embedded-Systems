#ifndef WARNINGSUBSYSTEM_H
#define WARNINGSUBSYSTEM_H
#include "bool.h"

// Warning Struct
typedef struct WarningAlarmData {
    unsigned int* temperatureRawPtr;
    unsigned int* bloodPressRawPtr;
    unsigned int* pulseRateRawPtr;
    unsigned short* batteryStatePtr; 
    unsigned char* tempOutOfRangePtr; // Warning, Orange
    unsigned char* pulseOutOfRangePtr; // Warning, Orange
    unsigned char* bpOutOfRangePtr; // Warning, Orange
    Bool* batteryWarningPtr; // Alarm, Red
    Bool* bpHigh; // Alarm, Red 
    Bool* tempHigh; // Didn't mentioned in the spec
    Bool* pulseLow; // Didn't mention in the spec
    Bool* warningAlarmFlag;
        
} warningSubsystemData;

void WarningAlarmSubsystemFunction(void* data);

#endif // WARNINGSUBSYSTEM_H
