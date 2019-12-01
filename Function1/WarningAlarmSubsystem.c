#include "globals.h"
#include "WarningAlarmSubsystem.h"
#include "bool.h"

void WarningAlarmSubsystemFunction(void *data)
{
    warningAlarmSubsystemData* warningAlarmData = (warningAlarmSubsystemData*) data;
    //the redefinition might not be necessary. Can directly use *(warningAlarmData->temperatureRawPtr)
    unsigned int temperatureRAW = *(warningAlarmData->temperatureRawPtr);
    unsigned int systolicPressRaw = *(warningAlarmData->systolicPressRawPtr);
    unsigned int diastolicPressRaw = *(warningAlarmData->diastolicPressRawPtr);
    unsigned int pulseRateRaw = *(warningAlarmData->pulseRateRawPtr);
    unsigned short batteryState = *(warningAlarmData->batteryStatePtr);
    unsigned char* bpOutOfRange = warningAlarmData->bpOutOfRangePtr;
    unsigned char* tempOutOfRange = warningAlarmData->tempOutOfRangePtr;
    unsigned char* pulseOutOfRange = warningAlarmData->pulseOutOfRangePtr;

    printf("System Warning:\n");
    //Temperature range 36.1C to 37.8C  //Temperature should not be unsigned int, float is more proper...
    if (temperatureRAW>36.1 && temperatureRAW<37.8)
        {tempOutOfRange=0;
        printf("GREEN:TEMPERATURE OK!\n");}
    else
        {tempOutOfRange=1;
        printf("RED:TEMPERATURE OUT OF RANGE!\n");}
    //Pulse range systolic pressure 120mmHg and diastolic pressure 80mmHg
    if (systolicPressRaw < 120 && diastolicPressRaw >80)
        {bpOutOfRange = 0;
        printf("GREEN: PRESSURE OK!\n");}
    else
        {bpOutOfRange = 1;
        printf("RED:PRESSURE OUT OF RANGE!\n");}
    //Pulse rate range 60 ~ 100 beats per minute
    if (pulseRateRaw>60 && pulseRateRaw<120 )
        {pulseOutOfRange = 0;
        printf("GREEN:PULSE RATE OK!\n");}
    else
        {pulseOutOfRange = 1;
        printf("RED:PULSE RATE OUT OF RANGE!\n");}
    //batteryState > 20*200
    if (batteryState> 0.2* 200)
       printf("GREEN:Battery OK!\n");
    else
        printf("RED:Battery Low!\n");
 //   printf("\n");
}
