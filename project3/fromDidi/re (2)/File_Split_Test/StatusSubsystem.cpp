#include "StatusSubsystem.h"
#include <Arduino.h>
#include "bool.h"

void StatusSubsystemFunction(void *data)
{
    statusSubsystemData* statusData = (statusSubsystemData*) data; 
    *(statusData->statusPtr)--;
    //unsigned int, so no need to worry about value smaller than 0; 
}
