#include <iostream>
#include "globals.h"

using namespace std;

int main()
{
    cout << "Hello world!";
    MeasureSubsystemData mstd;

    MeasureSubsystemFuction(&mstd);

    
    return 0;
}

void MeasureSubsystemFuction(void* data)
{
    MeasureSubsystemData* measureData = (MeasureSubsystemData*) data;
    int x = 0;
    // begin from here
    // if (*(measureData->measurementSelectionPtr) == 0) return; // segamation fault 

    // measureData->temperatureRawBuf[0] = 75;

    // cout << measureData->temperatureRawBuf[0];

    // tempRaw

}
