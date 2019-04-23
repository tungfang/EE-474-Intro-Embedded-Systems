#include "globals.h"

void initMeasureData()
{
MeasureData.temperatureRawPtr = &temperatureRaw;
MeasureData.systolicPressRawPtr = &systolicPressRaw;
MeasureData.diastolicPressRawPtr = &diastolicPressRaw;
MeausreData.pulseRateRawPtr = &pulseRateRaw;
}

void initComputerData()
{
ComputerData.temperatureRawPtr = &temperatureRaw;
ComputerData.systolicPressRawPtr = &systolicPressRaw;
ComputerData.diastolicPressRawPtr = &diastolicPressRaw;
ComputerData.pulseRateRawPtr = &pulseRateRaw;
ComputerData.tempCorrectedPtr = tempCorrected;
ComputerData.sysPressCorrectedPtr = tempCorrected;
ComputerData.diasCorrectedPtr = tempCorrected;
ComputerData.prCorrectedPtr = tempCorrected;
}

void initDisplayData()
{
DisplayData.tempCorrectedPtr = tempCorrected;
DisplayData.sysCorrectedPtr = sysCorrected;
DisplayData.diasCorrectedPtr = diasCorrected;
DisplayData.prCorrectedPtr = prCorrected;
DisplayData.batteryStatePtr = &batteryState;
}

void initWarningAlarmData()
{
WarningAlarmData.temperatureRawPtr = &temperatureRaw;
WarningAlarmData.systolicPressRawPtr = &systolicPressRaw;
WarningAlarmData.diastolicPressRawPtr = &diastolicPressRaw;
WarningAlarmData.pulseRateRawPtr = &pulseRateRaw;
WarningAlarmData.batteryStatePtr = &batteryState;
}

void initStatusData()
{
StatusData.batteryStatePtr = &batteryState;
}

void initScheduleData()
{

}

void init()
{
//Measurements
temperatureRaw = 75;
systolicPressRaw = 80;
diastolicPressRaw = 80;
pulseRateRaw = 50;
//Display
*tempCorrected = NULL;
*systolicPressCorrected = NULL;
*diastolicPressCorrected = NULL;
*pulseRateCorrected = NULL;
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

//initialized the datastruts
initMeasureData();
initComputerData();
DisplayData();
WarningAlarmData();
StatusData();
ScheduleData();

