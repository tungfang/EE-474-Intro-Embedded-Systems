#ifdef GLOBAL_DATA
#include "bool.h"
#include <stddef.h>
//Measurements
unsigned int temperatureRaw = 75;
unsigned int systolicPressRaw = 80;
unsigned int diastolicPressRaw = 80;
unsigned int pulseRateRaw = 50;

//Display
unsigned char* tempCorrected = NULL;
unsigned char* systolicPressCorrected = NULL;
unsigned char* diastolicPressCorrected = NULL;
unsigned char* pulseRateCorrected = NULL;

//Status
unsigned short batteryState = 200;

//Alarms
unsigned char bpOutOfRange = 0;
unsigned char tempOutOfRange = 0;
unsigned char pulseOutOfRange = 0;

//Warning
Bool bpHigh = FALSE;
Bool tempHigh = FALSE;
Bool pulseLow = FALSE;
#else
#include "bool.h"
#include <stddef.h>
//Measurements
extern unsigned int temperatureRaw;
extern unsigned int systolicPressRaw;
extern unsigned int diastolicPressRaw;
extern unsigned int pulseRateRaw;

//Display
extern unsigned char* tempCorrected;
extern unsigned char* systolicPressCorrected;
extern unsigned char* diastolicPressCorrected;
extern unsigned char* pulseRateCorrected;

//Status
extern unsigned short batteryState;

//Alarms
extern unsigned char bpOutOfRange;
extern unsigned char tempOutOfRange;
extern unsigned char pulseOutOfRange;

//Warning
extern Bool bpHigh;
extern Bool tempHigh;
extern Bool pulseLow;
#endif // GLOBAL_DATA_H

void Value_Init();
void Value_Update();
