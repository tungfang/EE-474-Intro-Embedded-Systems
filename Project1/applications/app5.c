// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>
#include <stdbool.h>

void delay(unsigned long number_of_seconds);
void f1Data(unsigned long delay1);
void f2Clear(unsigned long delay2); 

int main(void)
{
    // store user input of their desire delay rate
    unsigned long show_time, gone_time;

    printf("Please enter the desired showing time: \n");
    scanf("%d", &show_time);
    printf("Please enter the desired disappearing time: \n");
    scanf("%d", &gone_time);

	while (1) {
        f1Data(show_time);
        f2Clear(gone_time);
	}

	return 0;
}

void delay(unsigned long number_of_seconds)
{
    // Converting time into milli_seconds
    unsigned long milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}

// given a delay1 time for how long the data is showing on the console
void f1Data(unsigned long delay1)
{
    printf("\rA B C D");
    fflush(stdout);
    delay(delay1);    
}

// given a delay2 time for how long the data is disappearing from the console
void f2Clear(unsigned long delay2)
{
    printf("\r       ");
    fflush(stdout);
    delay(delay2);
}