#include "globals.h"
#include "ComputeSubsystem.h"
#include <stdio.h>

void ComputeSubsystemFunction(void *data)
{
    computeSubsystemData* computeData = (computeSubsystemData*) data;

    computeData->tempCorrectedPtr = computeData->temperatureRawPtr;
    *computeData->tempCorrectedPtr = (5+*(computeData->tempCorrectedPtr)*0.75);
    //*(computeData->tempCorrectedPtr) = (char) (*(computeData->temperatureRawPtr));

    computeData->diasCorrectedPtr = computeData->diastolicPressRawPtr;
    *(computeData->diasCorrectedPtr) = (char)(6+*(computeData->diasCorrectedPtr)*1.5);

    computeData->prCorrectedPtr = computeData->pulseRateRawPtr;
    *(computeData->prCorrectedPtr) = (char)(8+*(computeData->prCorrectedPtr)*3);

  //  printf("Corrected temperature is: %c \n Corrected systolicPressure is: %c \n Corrected diastolicPressure is: %c \n Corrected pulseRate is: %c \n",
   //        *(computeData->tempCorrectedPtr),*(computeData->sysPressCorrectedPtr), *(computeData->diastolicPressRawPtr), *(computeData->prCorrectedPtr));
    printf("Corrected temperature is %d \n",*computeData->tempCorrectedPtr);
    printf("ComputerSubsystem Runs OK\n");
}
