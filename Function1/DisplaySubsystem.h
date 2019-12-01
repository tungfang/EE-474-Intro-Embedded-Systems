#ifndef DISPLAYSUBSYSTEM_H_INCLUDED
#define DISPLAYSUBSYSTEM_H_INCLUDED

#include "bool.h"

typedef struct DisplaySubsystemData{
unsigned char* tempCorrectedPtr;
unsigned char* sysCorrectedPtr;
unsigned char* diasCorrectedPtr;
unsigned char* prCorrectedPtr;
unsigned short* batteryStatePtr;
}displaySubsystemData;

void DisplaySubsystemFunction (void* data);

#endif // DISPLAYSUBSYSTEM_H_INCLUDED
