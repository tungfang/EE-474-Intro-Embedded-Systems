// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>


void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}
// Driver code to test above function
int main(void)
{
    while (1) {
        // print A B C D to console, overwriting previous line
        // and persist for at least one second
        printf ("\rA B C D");
        fflush(stdout);
        delay(1);


        // then clear line and persist for at least one second
        printf ("\r  ");
        fflush(stdout);
        delay(1);

        printf ("\r    ");
        fflush(stdout);
        delay(1);

        printf ("\r      ");
        fflush(stdout);
        delay(1);

        printf ("\r        ");
        fflush(stdout);
        delay(1);

	}

	return 0;
}
