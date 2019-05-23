#include "circularBuffer.h"
#include <Arduino.h>
#include "bool.h"
#include "MeasureSubsystem.h"
#include "WarningSubsystem.h"
#include "ComputeSubsystem.h"
#include "CommunicationSubsystem.h"
#include "StatusSubsystem.h"
#include "TCB.h"
#include "taskqueue.h"
#include "scheduler.h"
#include "TFTKeyPadSubsystem.h"
#include "DisplaySubsystem.h"

#define LENGTH 8

#define TFTKEYPAD_TCB 0
#define MEASURE_TCB 1
#define COMPUTE_TCB 2
#define WARNINGALARM_TCB 3
#define DISPLAY_TCB 4
#define STATUS_TCB 5
#define COMMUNICATION_TCB 6

TCB tcbs[LENGTH];
Taskqueue queue;
Scheduler scheduler;

//TFT Key Pad Data
unsigned short measurementSelection;
unsigned short modeSelection;
unsigned short alarmAcknowledge; 
unsigned int ifback;

//Measurements Buffers
unsigned int temperatureRaw[8];
unsigned int systolicPressRaw[8];
unsigned int diastolicPressRaw[8];
unsigned int bloodPressRaw[16];
unsigned int pulseRateRaw[8];

//Compute Buffers & Communication Buffers
unsigned int temperatureCorrected[8];
unsigned int systolicPressCorrected[8];
unsigned int diastolicPressCorrected[8];
unsigned int pulseRateCorrected[8];
unsigned int bloodPressCorrected[16];

//Status Data
unsigned short batteryState;

//Warning and Alarms Data
unsigned char bpOutOfRange;
unsigned char tempOutOfRange;
unsigned char pulseOutOfRange;
Bool bpHigh;
Bool tempHigh;
Bool pulseLow;
Bool batteryWarning;
Bool Warning_Alarm_Flag;


measureSubsystemData measureData;
computeSubsystemData computeData;
warningSubsystemData warningData;
communicationSubsystemData communicationData;
statusSubsystemData statusData;
TFTKeyPadData tftData;
DisplaySubsystemData displayData;

void* measuredata = &measureData;
void* warningdata = &warningData;
void* computedata = &computeData;
void* communicationdata = &communicationData;
void* statusdata = &statusData;
void* tftdata = &tftData;
void* displaydata = &displayData;

void setup() {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));

  #ifdef USE_Elegoo_SHIELD_PINOUT
    Serial.println(F("Using Elegoo 2.8\" TFT Arduino Shield Pinout"));
  #else
    Serial.println(F("Using Elegoo 2.8\" TFT Breakout Board Pinout"));
  #endif

  // Serial.print("TFT size is "); Serial.print(tft.width()); Serial.print("x"); Serial.println(tft.height());
  initMeasureData();
  initWarningData();
  initComputeData();
  initTFTData();
  initCommunication();
  initStatusData();
  initDisplay();

  /////////////////TCB initiate////////////////////////
  initTCB(&tcbs[TFTKEYPAD_TCB], (void*)&tftData, TFTKeyPadSubsystemFunction, PRIORITY_HIGH);
  initTCB(&tcbs[MEASURE_TCB], (void*)&measureData, MeasureSubsystemFunction, PRIORITY_LOW);
  initTCB(&tcbs[COMPUTE_TCB], (void*)&computeData, ComputeSubsystemFunction, PRIORITY_LOW);
  initTCB(&tcbs[WARNINGALARM_TCB], (void*)&warningData, WarningAlarmSubsystemFunction, PRIORITY_HIGH);
  initTCB(&tcbs[DISPLAY_TCB], (void*)&displayData, DisplaySubsystemFunction, PRIORITY_LOW);
  initTCB(&tcbs[STATUS_TCB], (void*)&statusData, StatusSubsystemFunction, PRIORITY_LOW);
  initTCB(&tcbs[COMMUNICATION_TCB], (void*)&communicationData, CommunicationSubsystemFunction, PRIORITY_LOW);
  initTaskQueue(&queue);
}

void loop() {
  scheduleAndRun(&scheduler, &queue);
  reschedule();
  delay(1000);
}

//data initilization
void initMeasureData()
{
 measureData.temperatureRawPtr = temperatureRaw;
 measureData.systolicPressRawPtr = systolicPressRaw;
 measureData.diastolicPressRawPtr = diastolicPressRaw;
 measureData.bloodPressRawPtr = bloodPressRaw;
 measureData.pulseRateRawPtr = pulseRateRaw;
 measureData.measurementSelection = &measurementSelection;
  
 initBuffer(measureData.temperatureRawPtr, 8);
 initBufferLong(measureData.bloodPressRawPtr, 16);
 initBuffer(measureData.pulseRateRawPtr,8);
 // initBuffer(measureData.systolicPressRawPtr,8);
 // initBuffer(measureData.diastolicPressRawPtr,8);
 
 pushSample(measureData.temperatureRawPtr,75);
 pushSampleLong(measureData.bloodPressRawPtr,80, TRUE); // systolic
 pushSampleLong(measureData.bloodPressRawPtr,80, FALSE); // diastolic
 pushSample(measureData.pulseRateRawPtr,50);
 
 // pushSample(measureData.systolicPressRawPtr,80);
 // pushSample(measureData.diastolicPressRawPtr,80);
}

void initComputeData()
{
 computeData.temperatureRawPtr = temperatureRaw;
 computeData.systolicPressRawPtr = systolicPressRaw;
 computeData.diastolicPressRawPtr = diastolicPressRaw;
 computeData.pulseRateRawPtr = pulseRateRaw;
 computeData.measurementSelectionPtr = &measurementSelection;
 computeData.tempCorrectedPtr = temperatureCorrected;
 computeData.sysPressCorrectedPtr = systolicPressCorrected;
 computeData.diasPressCorrectedPtr = diastolicPressCorrected;
 computeData.prCorrectedPtr = pulseRateCorrected;
 computeData.bloodPressCorrectedPtr = bloodPressCorrected;

 initBuffer(computeData.tempCorrectedPtr, 8);
 initBuffer(computeData.sysPressCorrectedPtr,8);
 initBuffer(computeData.diasPressCorrectedPtr,8);
 initBuffer(computeData.prCorrectedPtr,8);
 pushSample(computeData.tempCorrectedPtr,39);
 pushSample(computeData.sysPressCorrectedPtr,169);
 pushSample(computeData.diasPressCorrectedPtr,126);
 pushSample(computeData.prCorrectedPtr,158);
}

void initCommunication()
{
  communicationData.tempCorrectedPtr = temperatureCorrected;
  communicationData.sysPressCorrectedPtr = systolicPressCorrected;
  communicationData.diasPressCorrectedPtr = diastolicPressCorrected;
  communicationData.bloodPressCorrectedPtr = bloodPressCorrected;
  communicationData.prCorrectedPtr = pulseRateCorrected;
  communicationData.statusPtr = &batteryState;
}

void initWarningData()
{
 bpHigh = FALSE;
 tempHigh = FALSE; 
 pulseLow = FALSE;
 batteryWarning = FALSE;
 Warning_Alarm_Flag = TRUE;
 bpOutOfRange = 0;
 tempOutOfRange = 0;
 pulseOutOfRange = 0;
 warningData.batteryWarningPtr = &batteryWarning;
 warningData.temperatureRawPtr = temperatureRaw;
 warningData.bloodPressRawPtr = bloodPressRaw;
 warningData.pulseRateRawPtr = pulseRateRaw;
 warningData.batteryStatePtr = &batteryState;
 warningData.warningAlarmFlag = &Warning_Alarm_Flag;
 warningData.bpHigh = &bpHigh;
 warningData.tempHigh = &tempHigh;
 warningData.pulseLow = &pulseLow;
 warningData.tempOutOfRangePtr = &tempOutOfRange;
 warningData.pulseOutOfRangePtr = &pulseOutOfRange;
 warningData.bpOutOfRangePtr = &bpOutOfRange;
}

void initStatusData()
{
  batteryState = 200;
  statusData.statusPtr = &batteryState;  
}

void initTFTData() 
{
  measurementSelection = 0;
  modeSelection = 0;
  alarmAcknowledge = 0; 
  ifback = 0;
  tftData.measurementSelectionPtr = &measurementSelection;
  tftData.modeSelectionPtr = &modeSelection;
  tftData.ifbackPtr = &ifback;
  tftData.alarmAcknowledgePtr = &alarmAcknowledge;
}

void initDisplay() 
{
  displayData.tempCorrectedPtr = temperatureCorrected;
  displayData.bloodPressCorrectedPtr = bloodPressCorrected;
  displayData.prCorrectedPtr = pulseRateCorrected;
  displayData.batteryStatePtr = &batteryState;
  displayData.bpOutOfRangePtr = &bpOutOfRange;
  displayData.tempOutOfRangePtr = &tempOutOfRange;
  displayData.pulseOutOfRangePtr = &pulseOutOfRange;
  displayData.measurementSelection = &measurementSelection;
  displayData.modeSelection = &modeSelection;
  displayData.ifback = &ifback;
}


void reschedule()
{
  addToHead(&queue, &tcbs[MEASURE_TCB]);
  addToHead(&queue,&tcbs[COMPUTE_TCB]);
  addToHead(&queue, &tcbs[WARNINGALARM_TCB]);
  addToHead(&queue, &tcbs[DISPLAY_TCB]);
  addToHead(&queue, &tcbs[STATUS_TCB]);
  addToHead(&queue, &tcbs[COMMUNICATION_TCB]);
  addToHead(&queue, &tcbs[TFTKEYPAD_TCB]);
}
