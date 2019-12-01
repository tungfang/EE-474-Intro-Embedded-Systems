#ifndef TCB_H_INCLUDED
#define TCB_H_INCLUDED

typedef enum {PIRORITY_REAL_TIME,PRIORITY_HIGH,PRIORITY_LOW} TaskPriority;

typedef struct myStruct
{
    void* taskDataPtr;
    void (*taskPtr)(void*);
    TaskPriority priority;
}TCB;

//invokes TCB's function, passing in the giving task info
//schedules the TCB to run at least the given number of
//miliseconds next from the current time
//
//return 1 if the task was invoked
//return 0 if the task was not invoked
void invoke(TCB* tcb);

//Initialized TCB with the given info
void intiTCB(TCB* tcb,void* taskDataPtr, void (*taskPtr)(void*),TaskPriority priority);


#endif // TCB_H_INCLUDED
