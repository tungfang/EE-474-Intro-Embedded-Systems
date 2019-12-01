#include "taskqueue.h"

void initTaskQueue(Taskqueue *queue, TCB* tcbArray, int length){
    queue->tcbArray = tcbArray;
    queue->length = length;
    queue->cur_index=0;
    //printf("Task queue initiated!\n");
}

//returns the next task in the queue
TCB* getNextTCB(Taskqueue* queue){
    TCB* nextTCB = &(queue->tcbArray)[queue->cur_index];
    queue->cur_index =(queue->cur_index+1)%queue->length;
    return nextTCB;
}
