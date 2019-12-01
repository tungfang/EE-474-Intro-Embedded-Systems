#ifndef STATUS_DATA_H_INCLUDED
#define STATUS_DATA_H_INCULDED

extern unsigned short batteryState;

// Holds batteryState pointer to the variables
typedef struct status
{
    unsigned short *batteryStatePtr;
} status_data;

void status(void *data);

#endif 