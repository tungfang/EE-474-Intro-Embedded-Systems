#include "globals.h"
#include "ComputeSubsystem.h"
#include <stdio.h>

void ComputeSubsystemFunction(void *data)
{
    computeSubsystemData* computeData = (computeSubsystemData*) data;

    *(computeData->tempCorrectedPtr) = (char)(5+0.75*(*computeData->temperatureRawPtr));
    *(computeData->sysPressCorrectedPtr) = (char)(9+2*(*computeData->systolicPressRawPtr));
    *(computeData->diasCorrectedPtr) = (char)(6+1.5*(*computeData->diastolicPressRawPtr));
    *(computeData->prCorrectedPtr) = (char)(8+3*(*computeData->pulseRateRawPtr));
    printf("Corrected temperature is: %c \n Corrected systolicPressure is: %c \n \
           Corrected diastolicPressure is: %c \n Corrected pulseRate is: %c \n", *(computeData->tempCorrectedPtr),\
           *(computeData->sysPressCorrectedPtr), *(computeData->diastolicPressRawPtr), *(computeData->prCorrectedPtr));
}
