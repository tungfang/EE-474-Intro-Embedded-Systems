// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>

void delay(unsigned long number_of_seconds);

// Driver code to test above function
int main(void)
{
    // note spec is unclear what offset B D should flash in relation to A and C
	while (1) {
        // Print each of these strings, overwriting the previous
        // line and persist for 1000 millis
        printf ("\rA   C  ");
        fflush(stdout);
        delay(1);

        printf ("\r       ");
        fflush(stdout);
        delay(1);

        printf ("\rA B C D");
        fflush(stdout);
        delay(1);

        printf ("\r  B   D");
        fflush(stdout);
        delay(1);
	}

	return 0;
}

void delay(unsigned long number_of_seconds)
{
    // Converting time into milli_seconds
    unsigned long milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}
