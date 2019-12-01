#include <stdio.h>
#include "globals.h"
#include "bool.h"
#include "MeasureSubsystem.h"
#include <stddef.h>
#include <stdbool.h>

bool even = true;
bool tempReverse = FALSE;
bool pulseReverse = FALSE;
bool systolicFlag = FALSE;
bool diastolicFlag = FALSE;


void MeasureSubsystemFunction(void* data) {
    //cast c_ptr to computerData structure type...
    measureSubsystemData* measureData = (measureSubsystemData*) data;

    if (even) {
        // tempRaw
        if (tempReverse) {
            if (*(measureData->temperatureRawPtr) < 15) {
                tempReverse = !tempReverse;
            } else {
                *(measureData->temperatureRawPtr) -= 2;
            }
        } else {
            if (*(measureData->temperatureRawPtr) > 50) {
                tempReverse = !tempReverse;
            } else {
                *(measureData->temperatureRawPtr) += 2;
            }
        }

        // systolicPressRaw
        if (*(measureData->systolicPressRawPtr) > 100) {
            *(measureData->systolicPressRawPtr) = 80;
            systolicFlag = TRUE; //set variable not sure, may be just local
        } else {
            *(measureData->systolicPressRawPtr) += 3;
        }

        // diastolicPressRaw
        if (measureData->diastolicPressRawPtr < 40) {
            diastolicFlag = TRUE;//set variable not sure, may be just local
            *(measureData->diastolicPressRawPtr) = 80;
        } else {
            *(measureData->diastolicPressRawPtr) -= 2;
        }

        //pulseRateRaw
        if (pulseReverse) {
            if (*(measureData->pulseRateRawPtr) < 15) {
                pulseReverse = !pulseReverse;
            } else {
                *(measureData->pulseRateRawPtr) += 1;
            }
        } else {
            if (*(measureData->pulseRateRawPtr) > 40) {
                pulseReverse = !pulseReverse;
            } else {
                *(measureData->pulseRateRawPtr) -= 1;
            }
        }


    } else {
        // tempRaw
        if (tempReverse) {
            if (*(measureData->temperatureRawPtr) < 15) {
                tempReverse = !tempReverse;
            } else {
                *(measureData->temperatureRawPtr) += 1;
            }
        } else {
            if (*(measureData->temperatureRawPtr) > 50) {
                tempReverse = !tempReverse;
            } else {
                *(measureData->temperatureRawPtr) -= 1;
            }
        }

        // systolicPressRaw
        if (*(measureData->systolicPressRawPtr) > 100) {
            *(measureData->systolicPressRawPtr) = 80;
            systolicFlag = TRUE;//set variable not sure, may be just local
        } else {
            *(measureData->systolicPressRawPtr) -= 1;
        }

        // diastolicPressRaw
        if (measureData->diastolicPressRawPtr < 40) {
            diastolicFlag = TRUE;//set variable not sure, may be just local
            *(measureData->diastolicPressRawPtr) = 80;
        } else {
            *(measureData->diastolicPressRawPtr) += 1;
        }

        //pulseRateRaw
        if (pulseReverse) {
            if (*(measureData->pulseRateRawPtr) < 15) {
                pulseReverse = !pulseReverse;
            } else {
                *(measureData->pulseRateRawPtr) -= 3;
            }
        } else {
            if (*(measureData->pulseRateRawPtr) > 40) {
                pulseReverse = !pulseReverse;
            } else {
                *(measureData->pulseRateRawPtr) += 3;
            }
        }
    }

    even = !even;
    printf("MeasureSubsystem Run Successfully!\n");
}
