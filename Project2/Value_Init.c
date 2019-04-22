#include <stdio.h>
#include "global_data.h"
#include "bool.h"
#include <stddef.h>

void Value_Init (void)
{
//Measurements
temperatureRaw = 75;
systolicPressRaw = 80;
diastolicPressRaw = 80;
pulseRateRaw = 50;

//Display
* tempCorrected = NULL;
* systolicPressCorrected = NULL;
* diastolicPressCorrected = NULL;
* pulseRateCorrected = NULL;

//Status
batteryState = 200;

//Alarms
bpOutOfRange = 0;
tempOutOfRange = 0;
pulseOutOfRange = 0;

//Warning
bpHigh = FALSE;
tempHigh = FALSE;
pulseLow = FALSE;
}
