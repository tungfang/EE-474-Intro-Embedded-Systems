#ifndef COMMUNICATION_H_INCLUDED
#define COMMUNICATION_H_INCLUDED

#include "bool.h"

typedef struct CommunicationSubsystemData{
    unsigned int *tempCorrectedPtr;
    unsigned int *sysPressCorrectedPtr;
    unsigned int *diasPressCorrectedPtr;
    unsigned int *bloodPressCorrectedPtr;
    unsigned int *prCorrectedPtr;
    unsigned int *statusPtr;
}communicationSubsystemData;

void CommunicationSubsystemFunction(void *data);

#endif // COMMUNICATION_H_INCLUDED
