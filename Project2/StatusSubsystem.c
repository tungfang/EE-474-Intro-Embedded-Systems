#include "globals.h"
#include "StatusSubsystem.h"

// Given a pointer to void and decrement battery state by 1 
// Return of a void
void status (void *data)
{
    status_data* dataptr = (status_data*) data;

    *(dataptr->batteryStatePtr) -= 1;
}