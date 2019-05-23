#include "ComputeSubsystem.h"
#include <Arduino.h>
#include "bool.h"
#include "circularBuffer.h"


void ComputeSubsystemFunction(void *data)
{
    unsigned int temperatureCorrected_t;
    unsigned int systolicPressCorrected_t;
    unsigned int diastolicPressCorrected_t;
    unsigned int pulseRateCorrected_t;
    unsigned int index_temperature;
    unsigned int index_systolicPressure;
    unsigned int index_diastolicPressure;
    unsigned int index_pulseRate;
    
    computeSubsystemData* computeData = (computeSubsystemData*) data;

    if (*(computeData->measurementSelectionPtr) == 1) {
        
      index_temperature = *(computeData->temperatureRawPtr+1);
      temperatureCorrected_t = *(computeData->temperatureRawPtr+index_temperature);
      temperatureCorrected_t = 5 + temperatureCorrected_t*0.75;  
      pushSample(computeData->tempCorrectedPtr,temperatureCorrected_t);
    
    } else if (*(computeData->measurementSelectionPtr) == 2) {
      
      index_systolicPressure = *(computeData->systolicPressRawPtr+1);
      systolicPressCorrected_t = *(computeData->systolicPressRawPtr+index_systolicPressure);
      systolicPressCorrected_t = 9 + systolicPressCorrected_t*2;
      index_diastolicPressure = *(computeData->diastolicPressRawPtr+1);
      diastolicPressCorrected_t = *(computeData->diastolicPressRawPtr+index_diastolicPressure);
      diastolicPressCorrected_t = 6 + diastolicPressCorrected_t*1.5;
      pushSample(computeData->sysPressCorrectedPtr,systolicPressCorrected_t);
      pushSample(computeData->diasPressCorrectedPtr,diastolicPressCorrected_t);
    
    } else if (*(computeData->measurementSelectionPtr) == 3) {
      index_pulseRate = *(computeData->pulseRateRawPtr+1);
      pulseRateCorrected_t = *(computeData->pulseRateRawPtr+index_pulseRate);
      pulseRateCorrected_t = 8 + pulseRateCorrected_t*3;
      pushSample(computeData->prCorrectedPtr,pulseRateCorrected_t);
    }

    
    

    printBuffer(computeData->tempCorrectedPtr, 8);
    printBuffer(computeData->sysPressCorrectedPtr, 8);
    printBuffer(computeData->diasPressCorrectedPtr, 8);
    printBuffer(computeData->prCorrectedPtr, 8);
}
