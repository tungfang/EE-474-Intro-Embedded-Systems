#include "WarningSubsystem.h"
#include <Arduino.h>
#include "bool.h"
#include "circularBuffer.h"



void WarningAlarmSubsystemFunction(void* data)
{  
  unsigned int temperatureRaw_t;
  unsigned int systolicPressRaw_t;
  unsigned int diastolicPressRaw_t;
  unsigned int pulseRateRaw_t;
  unsigned int index_temperature;
  unsigned int index_systolicPressure;
  unsigned int index_diastolicPressure;
  unsigned int index_pulseRate;
  
  warningSubsystemData* warningData = (warningSubsystemData*) data;
  index_temperature = *(warningData->temperatureRawPtr+1);
  index_systolicPressure = *(warningData->bloodPressRawPtr+1);
  index_diastolicPressure = *(warningData->bloodPressRawPtr+9);
  index_pulseRate = *(warningData->pulseRateRawPtr+1);
  temperatureRaw_t = *(warningData->temperatureRawPtr+index_temperature);
  systolicPressRaw_t = *(warningData->bloodPressRawPtr+index_systolicPressure);
  diastolicPressRaw_t = *(warningData->bloodPressRawPtr+index_diastolicPressure);
  pulseRateRaw_t = *(warningData->pulseRateRawPtr+index_pulseRate);
  
  if (temperatureRaw_t < 36.1 || temperatureRaw_t > 37.8) {
    *(warningData->tempOutOfRangePtr) = 1;          
  } else {
    *(warningData->tempOutOfRangePtr) = 0;  
  }

  if (systolicPressRaw_t < 120 || systolicPressRaw_t > 130 || diastolicPressRaw_t < 70 || diastolicPressRaw_t > 80) {
    *(warningData->bpOutOfRangePtr) = 1;
    if (systolicPressRaw_t > 130 * 1.2) {
      *(warningData->bpHigh) = TRUE;  
    } else {
      *(warningData->bpHigh) = FALSE;  
    }    
  } else {
    *(warningData->bpOutOfRangePtr) = 0;
  }

  if (pulseRateRaw_t < 60 || pulseRateRaw_t > 100) {
    *(warningData->pulseOutOfRangePtr) = 1;
  } else {
    *(warningData->pulseOutOfRangePtr) = 0;
  }

  if (*(warningData->batteryStatePtr) < 40) {
    *(warningData->batteryWarningPtr) = TRUE;
  } else {
    *(warningData->batteryWarningPtr) = FALSE;  
  }

  if (*(warningData->bpOutOfRangePtr) || *(warningData->tempOutOfRangePtr) || *(warningData->pulseOutOfRangePtr) || *(warningData->batteryWarningPtr)) {
    *(warningData->warningAlarmFlag) = TRUE;  
  } else {
    *(warningData->warningAlarmFlag) = FALSE;
  }
}
