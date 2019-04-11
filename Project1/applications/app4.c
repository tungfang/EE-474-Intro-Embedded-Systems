// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>
#include <stdbool.h>

void delay(unsigned long number_of_seconds);

// Driver code to test above function
int main(void)
{
    // store user input of their desire delay rate
    unsigned long AC_delay, BD_delay;
    bool flagAC, flagBD;

    printf("Please enter AC flashing rate: \n");
    scanf("%d", &AC_delay);
    printf("Please enter BD flashing rate: \n");
    scanf("%d", &BD_delay);

    // initiate AC and BD rate counters
    // letters appear iff their timer = 0
    unsigned long AC_count = 0; 
    unsigned long BD_count = 0;
    flagAC = 1;
    flagBD = 1;

	while (1) {
        // both timer are 0, print all
        if (flagAC == 1 && flagBD == 1)
        {
            printf("\rA B C D");
        } 
        else if (flagAC == 1) // print only AC since only AC timer = 0
        {
            printf("\rA   C  ");
            AC_count = 0; // reset after print
        } 
        else if (flagBD == 1) // print only BD since only BD timer = 0
        {
            printf("\r  B   D");
            BD_count == 0; // reset after print
        }
        else
        {
            printf("\r       "); // both timer aren't 0 so print empty string
        }
        
        AC_count++;
        BD_count++;
        // reset timer when timer is greate the falshing rate
        if (AC_count == AC_delay) 
        {
            AC_count = 0; 
            flagAC = !flagAC;
        }
        if (BD_count == BD_delay) 
        {
            BD_count = 0;
            flagBD = !flagBD;
        }
        fflush(stdout);
        delay(1);
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