#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

void GoToXY();
int delay_1();
int delay_2();

int main()
{
 bool flagAC=1,flagBD=1; //set the flag to decide which pattern to print. Pattern include "ABCD" "A C " " B D" "    "
 int delay1, delay2;
 int timer1, timer2;
 delay1=delay_1();
 delay2=delay_2();
 timer1=delay1;
 timer2=delay2;
 //printf("%d,%d",delay1,delay2);
 //Sleep(1000);
 while (1)
 {
     GoToXY(0,3);
     for (int i=0;i<delay1;i++)
        for (int j=0;j<delay2;j++)
        {
           if (flagAC==1&&flagBD==1)
           {
               printf("ABCD");
               Sleep(1000);
               GoToXY(0,3);
           }
           else if (flagAC==1&&flagBD==0)
           {
                printf("A C ");
                Sleep(1000);
                GoToXY(0,3);
           }
           else if (flagAC==0&flagBD==1)
           {
                printf(" B D");
                Sleep(1000);
                GoToXY(0,3);
           }
           else
           {
                printf("    ");
                Sleep(1000);
                GoToXY(0,3);
           }
           timer1--;
           timer2--;
           if (timer1==0)
           {
               flagAC = !flagAC;
               timer1=delay1;
           }
           if (timer2==0)
           {
               flagBD = !flagBD;
               timer2=delay2;
           }
        }

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

int delay_1()
{
 int time;
 printf("Frequency of AC in seconds: ");
 scanf("%d",&time);
 return time;
}

int delay_2()
{
 int time;
 printf("Frequency of BD in seconds: ");
 scanf("%d",&time);
 return time;
}
