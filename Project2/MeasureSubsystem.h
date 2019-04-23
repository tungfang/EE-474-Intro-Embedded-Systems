#ifndef CONSOLEDISPLAYSUBSYSTEM_H
#define CONSOLEDISPLAYSUBSYSTEM_H

typedef struct measureData {
    unsigned int* temperatureRawPtr;
    unsigned int* systolicPressRawPtr;
    unsigned int* diastolicPressRawPtr;
    unsigned int* pulseRateRawPtr;
}measureData;
void measureDataFunction(void* data);

#endif