#ifndef DISPLAYSUBSYSTEM_H_INCLUDED
#define DISPLAYSUBSYSTEM_H_INCLUDED

typedef struct DisplaySubsystemData{
    unsigned int* tempCorrectedPtr;
    unsigned int* bloodPressCorrectedPtr;
    unsigned int* prCorrectedPtr;
    unsigned short* batteryStatePtr;
    unsigned char *bpOutOfRangePtr;
    unsigned char *tempOutOfRangePtr;
    unsigned char *pulseOutOfRangePtr;
    unsigned short *measurementSelection;
    unsigned short *modeSelection;
    unsigned int *ifback;
} displaySubsystemData;

void DisplaySubsystemFunction(void* data);

#endif
