/* 5)Write a program that generates a table
showing the difference between "time1" calculated as
"time1 += deltaT" and "time2" calculated as
"time2 = i * deltaT", for iterations from 0 up to
an upper limit specified by the user. The user should also specify
a frequency for how frequently (s) he wants the results
printed in the table. So if they enter 10 for the frequency
you should print results every 10th time through the loop,
and if they enter 100, then print every 100th time through the loop,
etc. Hint: Use mod for the printing frequency. */

#include<stdio.h>

void main()
{
    int time1 = 0, time2 = 0, limit = 0, deltaT = 0, frequency;
    int i = 0;
    printf("Enter Limit, deltaT and Frequency values : ");
    scanf("%d %d %d", &limit, &deltaT, &frequency);
    printf("T1\tT2\tDifference");
    for(i = 0; i <= limit; i++)
    {
        time1 += deltaT;
        time2 = i*deltaT;
        if(i%frequency == 0 && i != 0)
          printf("\n%d\t%d\t%d", time1, time2, time2-time1);
    }
}
