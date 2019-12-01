#include "globals.h"
#include "DisplaySubsystem.h"
#include <stdio.h>

void DisplaySubsystemFunction (void* data)
{
    //cast the correct pointer
    displaySubsystemData* displayData = (displaySubsystemData*) data;
    printf ("DISPLAY SUBSYSTEM:\n");

}
