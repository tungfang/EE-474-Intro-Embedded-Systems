// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>
#include <stdbool.h>
#include "app8_f.h"



// Driver code to test above function
int main(void)
{
    // store user input of their desire delay rate
    unsigned long show_time, gone_time;

    printf("Please enter the desired showing time: \n");
    scanf("%d", &show_time);
    printf("Please enter the desired disappearing time: \n");
    scanf("%d", &gone_time);

	while (1) {
        f1Data(&show_time);
        f2Clear(&gone_time);
	}

	return 0;
}

