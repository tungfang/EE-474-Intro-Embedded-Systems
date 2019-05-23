#include "CommunicationSubsystem.h"
#include <Arduino.h>
#include "bool.h"
#include "circularBuffer.h"

void CommunicationSubsystemFunction(void *data)
{
  // get the original data results
    unsigned int temperatureCorrected_t;
    unsigned int systolicPressCorrected_t;
    unsigned int diastolicPressCorrected_t;
    unsigned int pulseRateCorrected_t;
    unsigned int batteryState_t;
    unsigned int index_temperature;
    unsigned int index_systolicPressure;
    unsigned int index_diastolicPressure;
    unsigned int index_pulseRate;
   //switch to char type and send to serial port
    unsigned char Temperature_char;
    unsigned char Systolic_char;
    unsigned char Diastolic_char;
    unsigned char Puserate_char;
    unsigned char Battery_char;
  
  communicationSubsystemData* communicationData = (communicationSubsystemData*) data;

  index_temperature = *(communicationData->tempCorrectedPtr+1);
  index_systolicPressure = *(communicationData->sysPressCorrectedPtr+1);
  index_diastolicPressure = *(communicationData->diasPressCorrectedPtr+1);
  index_pulseRate = *(communicationData->prCorrectedPtr+1);  
  temperatureCorrected_t = getCurrentValue(communicationData->tempCorrectedPtr);
  systolicPressCorrected_t = getCurrentValue(communicationData->sysPressCorrectedPtr);
  diastolicPressCorrected_t = getCurrentValue(communicationData->diasPressCorrectedPtr);
  pulseRateCorrected_t = getCurrentValue(communicationData->prCorrectedPtr);
  batteryState_t = *(communicationData->statusPtr);

  Temperature_char = (unsigned char) temperatureCorrected_t;
  Systolic_char = (unsigned char) systolicPressCorrected_t;
  Diastolic_char = (unsigned char) diastolicPressCorrected_t;
  Puserate_char = (unsigned char) pulseRateCorrected_t;
  Battery_char = (unsigned char) batteryState_t;

  Serial.print(Temperature_char);
  Serial.println(" C");
  Serial.print(Systolic_char);
  Serial.println(" mm Hg");
  Serial.print(Diastolic_char);
  Serial.println(" mm Hg");
  Serial.print(Battery_char);
  Serial.println("  remaining");
}
