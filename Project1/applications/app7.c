// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>
#include <stdbool.h>

void delay(unsigned long number_of_seconds);
void f1Data(unsigned long delay1, unsigned long delay2, char str[]);
void f2Clear(unsigned long delay2); 

int main(void)
{
    // store user input of their desire delay rate
    unsigned long AC_show_time, AC_gone_time, BD_show_time, BD_gone_time;

    printf("Please enter the showing time for AC: \n");
    scanf("%d", &AC_show_time);
    printf("Please enter the showing time for BD: \n");
    scanf("%d", &BD_show_time);

    printf("Please enter the disappearing time for AC: \n");
    scanf("%d", &AC_gone_time);
    printf("Please enter the disappearing time for BD: \n");
    scanf("%d", &BD_gone_time);

	while (1) {
        f1Data(AC_show_time, AC_gone_time, "A C ");
        f1Data(BD_show_time, BD_gone_time, " B D");
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
void f1Data(unsigned long delay1, unsigned long delay2, char str[])
{
    printf("\r%s", str);
    fflush(stdout);
    delay(delay1);
    printf("\r");    
    f2Clear(delay2);
}

// given a delay2 time for how long the data is disappearing from the console
void f2Clear(unsigned long delay2)
{
    printf("\r       ");
    fflush(stdout);
    delay(delay2);
}