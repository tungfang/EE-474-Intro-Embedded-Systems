#include "foo.h"

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