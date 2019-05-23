#ifndef MEASURE_H_INCLUDED
#define MEASURE_H_INCLUDED

#include "bool.h"

typedef struct MeasureSubsystemData{
    unsigned int *temperatureRawPtr;
    unsigned int *bloodPressRawPtr;
    unsigned int *systolicPressRawPtr;
    unsigned int *diastolicPressRawPtr;
    unsigned int *pulseRateRawPtr;
} measureSubsystemData;

void MeasureSubsystemFunction(void *data);

#endif // MEASURE_H_INCLUDED
