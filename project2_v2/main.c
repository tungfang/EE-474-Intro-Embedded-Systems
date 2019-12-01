#include <stdio.h>
#include "globals.h"
#include "TCB.h"
#include "scheduler.h"

#define LENGTH 5

//Declare the prototypes for the tasks
void get(void* aNumber);
void increment(void* aNumber);
void display(void* aNumber);

TCB tcbs[LENGTH];

int main(void)
{
    printf("Starting...\n");
    Scheduler scheduler;
    initScheduler(&scheduler);
    init();

    initTCB(&tcbs[0],(void*)&measureData,MeasureSubsystemFunction,PRIORITY_LOW);
    initTCB(&tcbs[1],(void*)&computeData,ComputeSubsystemFunction,PRIORITY_LOW);
    initTCB(&tcbs[2],(void*)&statusData,StatusSubsystemFunction,PRIORITY_LOW);
    initTCB(&tcbs[3],(void*)&displayData,DisplaySubsystemFunction,PRIORITY_LOW);
    initTCB(&tcbs[4],(void*)&warningAlarmData,WarningAlarmSubsystemFunction, PRIORITY_HIGH);

    Taskqueue queue;
    initTaskQueue(&queue, tcbs, LENGTH);

    while(1)
    {
        scheduleAndRun(&scheduler,&queue);
    }
    return 0;
}

void get(void* aNumber)
{
    int* number = (int*) aNumber;
    printf("GET()%d\n",*number);
    return;
}

void increment(void* aNumber)
{
    int* number = (int*) aNumber;
    printf("INCREMENT()%d\n",*number);
    return;
}

void display (void* aNumber )
{
    int* number = (int*) aNumber;
    printf("DISPLAY()%d\n",*number);
    return;
}
