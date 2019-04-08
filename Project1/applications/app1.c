#include <stdio.h>
#include <Windows.h>

int main()
{
    int i;
    for (int i = 0; i < 10; i++)
    {
        printf("ABCD");
        Sleep(1000);
        system("cls");
        Sleep(1000);
    }
    getch();
    return 0;
}
