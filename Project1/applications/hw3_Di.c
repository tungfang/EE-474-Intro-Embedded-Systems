#include <stdio.h>
#include <windows.h>
#include <conio.h>

void GoToXY();

int main()
{
 while (1)
 {
     printf("ABCD");
     Sleep(1000);
     GoToXY(0,0);
     printf("A C ");
     Sleep(1000);
     GoToXY(0,0);
     printf(" B D");
     Sleep(1000);
     GoToXY(0,0);
     printf("    ");
     Sleep(1000);
     GoToXY(0,0);
 }
 return 0;
 }

 void GoToXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!SetConsoleCursorPosition(hConsole, coord))
    {
        GetLastError();
    }
}


