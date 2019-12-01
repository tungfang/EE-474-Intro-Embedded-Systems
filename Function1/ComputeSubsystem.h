#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

#include "bool.h"

typedef struct ComputeSubsystemData{
    unsigned int *temperatureRawPtr;
    unsigned int *systolicPressRawPtr;
    unsigned int *diastolicPressRawPtr;
    unsigned int *pulseRateRawPtr;
    unsigned char *tempCorrectedPtr;
    unsigned char *sysPressCorrectedPtr;
    unsigned char *diasCorrectedPtr;
    unsigned char *prCorrectedPtr;
}computeSubsystemData;

void ComputeSubsystemFunction(void *data);

#endif // COMPUTER_H_INCLUDED
