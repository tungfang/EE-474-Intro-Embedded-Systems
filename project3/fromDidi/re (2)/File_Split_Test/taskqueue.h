#ifndef TASKQUEUE_H_INCLUDED
#define TASKQUEUE_H_INCLUDED

#include "TCB.h"

typedef struct Taskqueue
{
    TCB* head;
    TCB* tail;
    int length;
} Taskqueue;

void initTaskQueue(Taskqueue* queue);

//addToTail task insert new task into the task queue
void addToTail(Taskqueue* queue, TCB* tcb);
//addToHead task create the first task, or insert task at the beginning of the queue
void addToHead(Taskqueue* queue, TCB* tcb);

TCB *removeHead(Taskqueue* queue);
TCB *removeTail(Taskqueue* queue);

//returns the next task in the queue
TCB* getNextTCB(Taskqueue* queue);

#endif // TASKQUEUE_H_INCLUDED
