#include <iostream>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "MeasureSubsystem.h"


bool even = true;
bool tempReverse = false;
bool pulseReverse = false;
bool systolicFlag = false;
bool diastolicFlag = false;

MeasureSubsystem::MeasureSubsystem(void *data)
{
    //cast c_ptr to computerData structure type...
    measureSubsystemData* measureData = (measureSubsystemData*) data;
    if (*(measureData->measurementSelectionPtr)==0) return;
}
