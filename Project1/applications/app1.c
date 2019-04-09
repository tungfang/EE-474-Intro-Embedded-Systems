#include <stdio.h>
#include <time.h>


void delay(int number_of_seconds);

int main(void)
{
    while (1) {
        printf ("\rA B C D");
        fflush(stdout);
        delay(1);

        printf ("\r       ");
        fflush(stdout);
        delay(1);
	}

	return 0;
}

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