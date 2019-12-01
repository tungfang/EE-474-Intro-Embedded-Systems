#ifndef WARNINGALARMSUBSYSTEM_H_INCLUDED
#define WARNINGALARMSUBSYSTEM_H_INCLUDED

typedef struct WarningAlarmSubsystemData{

    unsigned int *temperatureRawPtr;
    unsigned int *systolicPressRawPtr;
    unsigned int *diastolicPressRawPtr;
    unsigned int *pulseRateRawPtr;
    unsigned short *batteryStatePtr;
    unsigned char *bpOutOfRangePtr;
    unsigned char *tempOutOfRangePtr;
    unsigned char *pulseOutOfRangePtr;
}warningAlarmSubsystemData;

void WarningAlarmSubsystemFunction (void* data);

#endif // WARNING_ALARM_H_INCLUDED
