#include "scheduler.h"
#include "clock.h"
#include "taskqueue.h"
#include "TCB.h"
#include <stdio.h>

//fill scheduler.h's definition via external length of the cycles in milliseconds
long long MAJOR_CYCLE = 1000;
long long MINOR_CYCLE = 100;

//waits until current cycle is over
void scheduleAndRun (Scheduler* scheduler, Taskqueue* queue){
    printf("Running ScheduleAndRun...\n");
    long long currentTime = getTimeMillis();

    int isMajor = currentTime>= scheduler->nextEndMajor; //are you after a major cycle
    int isMinor = currentTime>= scheduler->nextEndMinor;

    cycleLevel level = CYCLE_REAL_TIME;

    if (isMinor){
        scheduler->nextEndMinor = currentTime + MINOR_CYCLE;
        level = CYCLE_MINOR;
    }
    if (isMajor){
        scheduler->nextEndMajor = currentTime +  MAJOR_CYCLE;
        level = CYCLE_MAJOR;
    }
    printf ("currentTimee is %d\n",currentTime);
    printf ("nextEndMajor is %d\n",scheduler->nextEndMajor);
    printf ("nextEndMinor is %d\n",scheduler->nextEndMinor);

    for (int i=0;i<queue->length;i++){
        TCB* curTCB=getNextTCB(queue);
        printf ("Value of Level is %d\n",level);
        if(level == CYCLE_MAJOR){
            //if a major cycle run everything
            invoke(curTCB);
            printf("CycleMajor.\n");
        }
        else if (level == CYCLE_MINOR && curTCB->priority !=PRIORITY_LOW){
            invoke(curTCB);
            printf("CycleMinor.\n");
        }
        else if (level==CYCLE_REAL_TIME && curTCB->priority == PIRORITY_REAL_TIME){
            invoke(curTCB);
            printf("Realtime.\n");
        }
        else
            printf("ERROR!\n");
    }
}
   void initScheduler(Scheduler* scheduler){
    scheduler->nextEndMajor = 0;
    scheduler->nextEndMinor = 0;
   }
