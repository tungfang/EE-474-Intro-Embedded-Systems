#include <stdio.h>
#include "global_data.h"
#include "bool.h"
#include "measure_Data.h"
#include <stddef.h>
#include <stdbool.h>

bool even = true;
bool tempReverse = FALSE;
bool pulseReverse = FALSE;
//bool systolicFlag = FALSE;
//bool diastolicFlag = FALSE;


void measureDataFunction(void* data) {
    //cast c_ptr to computerData structure type...
    measureData *measure_ptr = (measureData*) data;
    
    if (even) {
        // tempRaw
        if (tempReverse) {
            if (*(measure_ptr->temperatureRawPtr) < 15) {
                tempReverse = !tempReverse;
            } else {
                *(measure_ptr->temperatureRawPtr) -= 2;
            }
        } else {
            if (*(measure_ptr->temperatureRawPtr) > 50) {
                tempReverse = !tempReverse;
            } else {
                *(measure_ptr->temperatureRawPtr) += 2;
            }
        }

        // systolicPressRaw
        if (*(measure_ptr->systolicPressRawPtr) > 100) {
            *(measure_ptr->systolicPressRawPtr) = 80;
            *(measure_ptr->systolicPressMeasurementCompletePrt) = TRUE; //set variable not sure, may be just local
        } else {
            *(measure_ptr->systolicPressRawPtr) += 3;
        }
        
        // diastolicPressRaw
        if (measure_ptr->diastolicPressRawPtr < 40) {
            *(measure_ptr->diastolicPressMeasurementCompletePtr) = TRUE;//set variable not sure, may be just local
            *(measure_ptr->diastolicPressMeasurementCompletePtr) = 80;
        } else {
            *(measure_ptr->diastolicPressRawPtr) -= 2;
        }

        //pulseRateRaw
        if (pulseReverse) {
            if (*(measure_ptr->pulseRateRawPtr) < 15) {
                pulseReverse = !pulseReverse;
            } else {
                *(measure_ptr->pulseRateRawPtr) += 1;
            }
        } else {
            if (*(measure_ptr->pulseRateRawPtr) > 40) {
                pulseReverse = !pulseReverse;
            } else {
                *(measure_ptr->pulseRateRawPtr) -= 1;
            }
        }


    } else {
        // tempRaw
        if (tempReverse) {
            if (*(measure_ptr->temperatureRawPtr) < 15) {
                tempReverse = !tempReverse;
            } else {
                *(measure_ptr->temperatureRawPtr) += 1;
            }
        } else {
            if (*(measure_ptr->temperatureRawPtr) > 50) {
                tempReverse = !tempReverse;
            } else {
                *(measure_ptr->temperatureRawPtr) -= 1;
            }
        }

        // systolicPressRaw
        if (*(measure_ptr->systolicPressRawPtr) > 100) {
            *(measure_ptr->systolicPressRawPtr) = 80;
            *(measure_ptr->systolicPressMeasurementCompletePrt) = TRUE;//set variable not sure, may be just local
        } else {
            *(measure_ptr->systolicPressRawPtr) -= 1;
        }

        // diastolicPressRaw
        if (measure_ptr->diastolicPressRawPtr < 40) {
            *(measure_ptr->diastolicPressMeasurementCompletePtr) = TRUE;//set variable not sure, may be just local
            *(measure_ptr->diastolicPressMeasurementCompletePtr) = 80;
        } else {
            *(measure_ptr->diastolicPressRawPtr) += 1;
        }
        
        //pulseRateRaw
        if (pulseReverse) {
            if (*(measure_ptr->pulseRateRawPtr) < 15) {
                pulseReverse = !pulseReverse;
            } else {
                *(measure_ptr->pulseRateRawPtr) -= 3;
            }
        } else {
            if (*(measure_ptr->pulseRateRawPtr) > 40) {
                pulseReverse = !pulseReverse;
            } else {
                *(measure_ptr->pulseRateRawPtr) += 3;
            }
        }
    } 

    even = !even;
}