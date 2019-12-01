#ifndef STATUSSUBSYSTEM_H_INCLUDED
#define STATUSSUBSYSTEM_H_INCLUDED

typedef struct StatusSubsystemData{
    unsigned short* batteryStatePtr;

}statusSubsystemData;

void StatusSubsystemFunction (void *data);
#endif // STATUSSUBSYSTEM_H_INCLUDED
