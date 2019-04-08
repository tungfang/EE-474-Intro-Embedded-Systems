#include <stdio.h>
#include <Windows.h>

void removeChar(char arr[], size_t len, size_t pos);

int main()
{
    char arr [256] = "ABCD";
    int i;
    for (int i = 0; i < 10; i++)
    {
        printf(arr);
        removeChar(arr, strlen(arr), 0);
        Sleep(1000);
        system("cls");
        Sleep(1000);
    }
    getch();
    return 0;
}

void removeChar (char arr[], size_t len, size_t pos)
{
    memmove(arr + pos, arr + (pos + 1), (len - pos) + 1);
}
