#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

#include "bool.h"

typedef struct StatusSubsystemData{
    unsigned short *statusPtr;
}statusSubsystemData;

void StatusSubsystemFunction(void *data);

#endif // STATUS_H_INCLUDED
