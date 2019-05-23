#include "scheduler.h"
#include "taskqueue.h"
#include "TCB.h"
#include <stdio.h>
#include "arduino.h"



//waits until current cycle is over
void scheduleAndRun (Scheduler* scheduler, Taskqueue* queue){
    //printf("Running ScheduleAndRun...\n");
    //get the current time
    long long currentTime = millis();

    int isMajor = currentTime>= scheduler->nextEndMajor; //nextEndMajor updates when currentTime larger than the previous nextEndMajor+MAJOR_CYCLE,if not, just waits
    int isMinor = currentTime>= scheduler->nextEndMinor; //nextEndMinor updates when currentTime larger than the previous nextEndMinor+MINOR_CYCLE, if not, just waits

    cycleLevel level = CYCLE_REAL_TIME;

    if (isMinor){
        scheduler->nextEndMinor = currentTime + MINOR_CYCLE;
        level = CYCLE_MINOR;
    }
    if (isMajor){
        scheduler->nextEndMajor = currentTime +  MAJOR_CYCLE;
        level = CYCLE_MAJOR;
    }

    while(queue->length>0){
        //Cycle through the current TCB each time
        TCB* curTCB=getNextTCB(queue);
        //conditions to decide if run the current TCB or not
        if(level == CYCLE_MAJOR){
            //if a major cycle run everything
            invoke(curTCB);
        //    printf("CycleMajor.\n");
        }
        else if (level == CYCLE_MINOR && curTCB->priority !=PRIORITY_LOW){
            invoke(curTCB);
        //    printf("CycleMinor.\n");
        }
        else if (level==CYCLE_REAL_TIME && curTCB->priority == PIRORITY_REAL_TIME){
            invoke(curTCB);
         //   printf("Realtime.\n");
        }
    }
}

   void initScheduler(Scheduler* scheduler){
    scheduler->nextEndMajor = 0;
    scheduler->nextEndMinor = 0;
   }
