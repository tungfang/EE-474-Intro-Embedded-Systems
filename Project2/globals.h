#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include <stddef.h>
#include "bool.h"
#include "MeasureSubsystem.h"
#include "ComputeSubsystem.h"
#include "DisaplySubsystem.h"
#include "WarningAlarmSubsystem.h"
#include "StatusSubsystem.h"
#include "SchedulerSubsystem.h"

//Measurements
unsigned int temperatureRaw;
unsigned int systolicPressRaw;
unsigned int diastolicPressRaw;
unsigned int pulseRateRaw;
//Display
unsigned char* tempCorrected;
unsigned char* systolicPressCorrected;
unsigned char* diastolicPressCorrected;
unsigned char* pulseRateCorrected;
//Status
unsigned short batteryState;
//Alarms
unsigned char bpOutOfRange;
unsigned char tempOutOfRange;
unsigned char pulseOutOfRange;
//Warning
Bool bpHigh;
Bool tempHigh;
Bool pulseLow;

//static allocation to struct
MeasureSubsystemData measureData;
ComputeSubsystemData computerData;
DisplaySubsystemData displayData;
WarningAlarmSubsystemData warningAlarmData;
StatusSubsystemData statusData;
SchedulerSubsystemData scheduleData;

void init();

#endif // GLOBALS_H_INCLUDED
