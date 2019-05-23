#ifndef TFTKEYPADSUBSYSTEM_H_INCLUDED
#define TFTKEYPADSUBSYSTEM_H_INCLUDED

typedef struct TFTKeyPadData{
    unsigned short *measurementSelectionPtr;
    unsigned short *modeSelectionPtr;
    unsigned short *alarmAcknowledgePtr;
    unsigned int *ifbackPtr;
}TFTKeyPadData; 

void TFTKeyPadSubsystemFunction(void* data);

#endif
