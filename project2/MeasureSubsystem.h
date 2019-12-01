#ifndef MEASURESUBSYSTEM_H
#define MEASURESUBSYSTEM_H


class MeasureSubsystem
{
    typedef struct MeasureSubsystemData{
        unsigned int *temperatureRawPtr;
        unsigned int *bloodPressRawPtr;
        unsigned int *pulseRateRawPtr;
        unsigned short *measurementSelectionPtr;
    }

    public:
        MeasureSubsystem(void *data);

};

#endif // MEASURESUBSYSTEM_H
