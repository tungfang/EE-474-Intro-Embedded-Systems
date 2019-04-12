#include "foo.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}

void f1Data(unsigned long *delay1)
{
    printf("\rA B C D");
    fflush(stdout);
    delay(*delay1);    
}

void f2Clear(unsigned long *delay2)
{
    printf("\r       ");
    fflush(stdout);
    delay(*delay2);
}