#include "globals.h"
#include <stdio.h>

void initMeasureData()
{
measureData.temperatureRawPtr = &temperatureRaw;
measureData.systolicPressRawPtr = &systolicPressRaw;
measureData.diastolicPressRawPtr = &diastolicPressRaw;
measureData.pulseRateRawPtr = &pulseRateRaw;
}

void initComputerData()
{
computeData.temperatureRawPtr = &temperatureRaw;
computeData.systolicPressRawPtr = &systolicPressRaw;
computeData.diastolicPressRawPtr = &diastolicPressRaw;
computeData.pulseRateRawPtr = &pulseRateRaw;
computeData.tempCorrectedPtr = tempCorrected;
computeData.sysPressCorrectedPtr = systolicPressCorrected;
computeData.diasCorrectedPtr = diastolicPressCorrected;
computeData.prCorrectedPtr = pulseRateCorrected;
}

void initDisplayData()
{
displayData.tempCorrectedPtr = tempCorrected;
displayData.sysCorrectedPtr = systolicPressCorrected;
displayData.diasCorrectedPtr = diastolicPressCorrected ;
displayData.prCorrectedPtr = pulseRateCorrected;
displayData.batteryStatePtr = &batteryState;
}

void initWarningAlarmData()
{
warningAlarmData.temperatureRawPtr = &temperatureRaw;
warningAlarmData.systolicPressRawPtr = &systolicPressRaw;
warningAlarmData.diastolicPressRawPtr = &diastolicPressRaw;
warningAlarmData.pulseRateRawPtr = &pulseRateRaw;
warningAlarmData.batteryStatePtr = &batteryState;
}

void initStatusData()
{
statusData.batteryStatePtr = &batteryState;
}

//void initScheduleData()

void init()
{
//Measurements
temperatureRaw = 75;
systolicPressRaw = 80;
diastolicPressRaw = 80;
pulseRateRaw = 50;
//Display
tempCorrected = NULL;
systolicPressCorrected = NULL;
diastolicPressCorrected = NULL;
pulseRateCorrected = NULL;
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

//initialized the datastruts
initMeasureData();
initComputerData();
initDisplayData();
initWarningAlarmData();
initStatusData();

//printf("initiate values successfully\n");
}
