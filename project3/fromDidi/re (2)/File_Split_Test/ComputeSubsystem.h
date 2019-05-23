#ifndef COMPUTE_H_INCLUDED
#define COMPUTE_H_INCLUDED

#include "bool.h"

typedef struct ComputeSubsystemData{
    unsigned int *temperatureRawPtr;
    unsigned int *systolicPressRawPtr;
    unsigned int *diastolicPressRawPtr;
    unsigned int *pulseRateRawPtr;
    unsigned int *tempCorrectedPtr;
    unsigned int *sysPressCorrectedPtr;
    unsigned int *diasPressCorrectedPtr;
    unsigned int *prCorrectedPtr;
    unsigned int *bloodPressCorrectedPtr;
    unsigned short *measurementSelectionPtr;
}computeSubsystemData;

void ComputeSubsystemFunction(void *data);

#endif // COMPUTE_H_INCLUDED
