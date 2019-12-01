#include "globals.h"
#include "StatusSubsystem.h"

void StatusSubsystemFunction(void* data)
{
    statusSubsystemData* statusData = (statusSubsystemData*) data;
    *(statusData->batteryStatePtr)--;
    printf("The battery status is: %d\n",*(statusData->batteryStatePtr));
}
