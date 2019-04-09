// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>

void delay(int number_of_seconds);

// Driver code to test above function
int main(void)
{
    int AC_delay, BD_delay, LCM;
    
    printf("Please enter AC flashing rate: \n");
    scanf("%d", &AC_delay);
    printf("Please enter BD flashing rate: \n");
    scanf("%d", &BD_delay);

    int AC_count = 0; 
    int BD_count = 0;
    // note spec is unclear what offset B D should flash in relation to A and C
	while (1) {
        if (AC_count == 0 && BD_count == 0)
        {
            printf("\rA B C D");
        } 
        else if (AC_count == 0)
        {
            printf("\rA   C  ");
            AC_count = 0;
        } 
        else if (BD_count == 0)
        {
            printf("\r  B   D");
            BD_count == 0;
        }
        else
        {
            printf("\r       ");
        }
        
        AC_count++;
        BD_count++;
        if (AC_count > AC_delay) 
        {
            AC_count = 0;
        }
        if (BD_count > BD_delay) 
        {
            BD_count = 0;
        }
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
    while (clock() < start_time + milli_seconds);
}