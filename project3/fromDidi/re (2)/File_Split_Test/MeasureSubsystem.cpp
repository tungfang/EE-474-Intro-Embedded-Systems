#include "MeasureSubsystem.h"
#include <Arduino.h>
#include "bool.h"
#include "circularBuffer.h"

bool even = TRUE;
bool tempReverse = TRUE;
bool pulseReverse = TRUE;
bool systolicFlag = FALSE;
bool diastolicFlag = FALSE;

void MeasureSubsystemFunction(void* data) {
    unsigned int temperatureRaw_t;
    unsigned int systolicPressRaw_t;
    unsigned int diastolicPressRaw_t;
    unsigned int pulseRateRaw_t;
    unsigned int index_temperature;
    unsigned int index_systolicPressure;
    unsigned int index_diastolicPressure;
    unsigned int index_pulseRate;
    
    //cast c_ptr to computerData structure type...
    measureSubsystemData* measureData = (measureSubsystemData*) data;
    index_temperature = *(measureData->temperatureRawPtr+1);
    index_systolicPressure = *(measureData->bloodPressRawPtr+1);
    index_diastolicPressure = *(measureData->bloodPressRawPtr+9);
    index_pulseRate = *(measureData->pulseRateRawPtr+1);
    temperatureRaw_t = *(measureData->temperatureRawPtr+index_temperature);
    systolicPressRaw_t = *(measureData->bloodPressRawPtr+index_systolicPressure);
    diastolicPressRaw_t = *(measureData->bloodPressRawPtr+index_diastolicPressure);
    pulseRateRaw_t = *(measureData->pulseRateRawPtr+index_pulseRate);
 
    if (even) {
        // tempRaw
        if (!tempReverse) {
          temperatureRaw_t += 2;
          if (temperatureRaw_t > 50) {
              tempReverse = !tempReverse;
          } 
        } else {
          temperatureRaw_t -= 2;
          if (temperatureRaw_t < 15) {
              tempReverse = !tempReverse;
          }
        }
        // systolicPressRaw
        systolicPressRaw_t += 3;
        if (systolicPressRaw_t > 100) {
          systolicPressRaw_t = 80;
          systolicFlag = TRUE; // maybe send to globals? 
        } else {
          systolicFlag = FALSE;  
        }
        
        // diastolicPressRaw
        diastolicPressRaw_t -= 2;
        if (diastolicPressRaw_t < 40) {
            diastolicFlag = TRUE; //set variable not sure, may be just local
            diastolicPressRaw_t = 80;
        } else {
            diastolicFlag = FALSE;
        }

        //pulseRateRaw
        if (!pulseReverse) {
          pulseRateRaw_t -= 1;
            
        } else {
          pulseRateRaw_t += 1;
        }
    } else {
        // tempRaw
        if (!tempReverse) {
            temperatureRaw_t -= 1;
        } else {
          temperatureRaw_t += 1;
        }
       // systolicPressRaw
        systolicPressRaw_t -= 1;

        // diastolicPressRaw
        diastolicPressRaw_t += 1;


        //pulseRateRaw
        if (!pulseReverse) {
          pulseRateRaw_t += 3;
          if (pulseRateRaw_t > 40) {
             pulseReverse = !pulseReverse;
          } 
        } else {
          pulseRateRaw_t -= 3;
          if (pulseRateRaw_t < 15) {
             pulseReverse = !pulseReverse;
          }
        }
    }
    even = !even;
    pushSample(measureData->temperatureRawPtr,temperatureRaw_t);
    pushSampleLong(measureData->bloodPressRawPtr, systolicPressRaw_t, TRUE); // systolic
    pushSampleLong(measureData->bloodPressRawPtr,diastolicPressRaw_t, FALSE); // diastolic
    pushSample(measureData->pulseRateRawPtr,pulseRateRaw_t);  
//  pushSample(measureData->systolicPressRawPtr,systolicPressRaw_t);
//  pushSample(measureData->diastolicPressRawPtr,diastolicPressRaw_t);
    
    printBuffer(measureData->temperatureRawPtr, 8);
    printBuffer(measureData->bloodPressRawPtr, 16);
    printBuffer(measureData->pulseRateRawPtr, 8);
//  printBuffer(measureData->systolicPressRawPtr, 8);
//  printBuffer(measureData->diastolicPressRawPtr, 8);
    
}
