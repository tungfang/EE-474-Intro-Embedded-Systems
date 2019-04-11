#include "app8_f.h"
#include <time.h>
#include <stdio.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}

// Given the reference of the delay1 time for how long the data is shown in the console
void f1Data(unsigned long *delay1)
{
    printf("\rA B C D");
    fflush(stdout);
    delay(*delay1);
}

// Given the reference of the delay2 time for how long the data is disappearing from the console
void f2Clear(unsigned long *delay2)
{
    printf("\r       ");
    fflush(stdout);
    delay(*delay2);
}

