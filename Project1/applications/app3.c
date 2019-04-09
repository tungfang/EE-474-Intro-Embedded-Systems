// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>

void delay(int number_of_seconds);

// Driver code to test above function
int main(void)
{
    int count = 0;
    // note spec is unclear what offset B D should flash in relation to A and C
	while (1) {
        if (count % 6 == 0) 
            printf("\rA B C D");
        else if (count % 6 == 1 || count % 6 ==5)
            printf("\r       ");
        else if (count % 6 == 2 || count % 6 == 4)
            printf("\rA   C  ");
        else
            printf("\r  B   D");
        
        count++;
        fflush(stdout);
        delay(1);
	}

	return 0;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}
