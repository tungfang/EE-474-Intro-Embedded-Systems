#include <iostream>
#include "globals.h"
#include "MeasureSubsystem.h"
#include "ComputeSubsystem.h"
#include "DisplaySubsystem.h"
#include "StatusSubsystem.h" 
#include "WarningSubsystem.h"
#include "KeypadSubsystem.h"

using namespace std;

int main()
{
    cout << "Hello world!";
    init();
    return 0;
}

void init()
{
    // Measurements
    temperatureRawBuf[0] = 75;
    bloodPressRawBuf[0] = 80;
    pulseRateRawBuf[0] = 0;
    
    // TFT KeyPad
    functionSelect = 0;
    measurementSelection = 0;
    alarmAcknowledge = 0;

    // Status
    batteryState = 200;

    //Alarm
    bpOutOfRange = 0;
    tempOutOfRange = 0;
    pulseOutOfRange = 0;

    // Warning
    bpHigh = FALSE;
    tempHigh = FALSE;
    pulseLow = FALSE;

    // TCB Linked List
    linkedListData.head = NULL;
    linkedListData.tail = NULL;
    linkedListTCB.head = NULL;
    linkedListTCB.tail = NULL;

    // initialize index 
    tempRawIndex = bpRawIndex = prRawIndex = tempCorrectIndex = bpCorrectedIndex = prCorrectedIndex = 1;

    measureSelection = NONE;
    acknowledge = NONE;

    measureData.temperatureRawBuf = temperatureRawBuf;
    measureData.bloocPressRawBuf = bloodPressRawBuf;
    measureData.pulseRateRawBuf = pulseRateRawBuf;
    measureData.measurementSelectionPtr = &measureSelection;

    computeData.temperatureRawBuf = temperatureRawBuf;
    computeData.bloodPressRawBuf = bloodPressRawBuf;
    computeData.pulseRateRawBuf = pulseRateRawBuf;
    computeData.measurementSelectionPtr = &measureSelection;
    computeData.temperatureCorrectedBuf = temperatureCorrectedBuf;
    computeData.bloodPressCorrectedBuf = bloodPressCorrectedBuf;
    computeData.pulseRateCorrectedBuf = pulseRateCorrectedBuf;

    displayData.temperatureCorrectedBuff = temperatureCorrectedBuf;
    displayData.bloodPressCorrectedBuf = bloodPressCorrectedBuf;
    displayData.pulseRateCorrectedBuf = pulseRateCorrectedBuf;
    displayData.batteryState = &batteryState;

    warningAlarmData.temperatureRawBuf = temperatureRawBuf;
    warningAlarmData.bloodPressRawBuf = bloodPressRawBuf;
    warningAlarmData.pulseRateRawBuf = pulseRateRawBuf;
    warningAlarmData.batteryState = &batteryState;

    statusData.batteryState = &batteryState;

    keyData.measurementSelection = &measureSelection;
    keyData.alarmAcknowledge = &acknowledge;

    taskQueue[0].taskDataPtr = &measureData;
    taskQueue[1].taskDataPtr = &computeData;
    taskQueue[2].taskDataPtr = &displayData;
    taskQueue[3].taskDataPtr = &warningAlarmData;
    taskQueue[4].taskDataPtr = &statusData;
    taskQueue[5].taskDataPtr = &keyData;
    taskQueue[6].taskDataPtr = &displayData;
 
    // taskQueue[0].taskPtr = &MeasureSubsystemFuction;
    // taskQueue[1].taskPtr = &ComputeSubsystemFunction;
    // taskQueue[2].taskPtr = &DisplaySubsystemFunction;
    // taskQueue[3].taskPtr = &WarningAlarmSubsystemFunction;
    // taskQueue[4].taskPtr = &StatusSubsystemFunction;
    // taskQueue[5].taskPtr = &KeypadSubsystemFunction;
}

