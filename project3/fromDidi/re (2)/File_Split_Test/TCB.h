#ifndef TCB_H_INCLUDED
#define TCB_H_INCLUDED

typedef enum {PIRORITY_REAL_TIME,PRIORITY_HIGH,PRIORITY_LOW} TaskPriority;

typedef struct Node    //Change myStruct to Node
{
    void* taskDataPtr;  //pointer that stores the address of the task data struct
    void (*taskPtr)(void*);  //pointer that stores the address of the tasks, function input variable is void* type
    TaskPriority priority;
    struct Node* next; //pointer that stores the address of the right node
    struct Node* prev;  //pointer that stores the address of the left node
}TCB;
/* above code does not allocate memory but it just tells the compiler that our node composed of three variables vise *left, data, *right*/

//invokes TCB's function, passing in the giving task info
//schedules the TCB to run at least the given number of
//miliseconds next from the current time
//
//return 1 if the task was invoked
//return 0 if the task was not invoked
void invoke(TCB* tcb);

//Initialized TCB with the given info
void initTCB(TCB* tcb,void* taskDataPtr, void (*taskPtr)(void*),TaskPriority priority);


#endif // TCB_H_INCLUDED
