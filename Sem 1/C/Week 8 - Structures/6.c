/* Cricket Directory */

#include<stdio.h>

struct player
{
    int runs, wickets, catchesTaken, catchesDropped, runOuts;
    char name[30], role[10], specDes[2];
}p[10];

void main()
{
    int i, size;
    printf("Enter Number of Players : ");
    scanf("%d", &size);
    for(i = 0; i < size; i++)
    {
        printf("Enter Details of %d:\n", i+1);
        printf("(Name, Runs, Wickets, catchesTaken, catchesDropped, Role, Special Designation)\n");
        scanf("%s %d %d %d %d %s %s", p[i].name, &p[i].runs, &p[i].wickets, &p[i].catchesTaken, &p[i].catchesDropped, p[i].role, p[i].specDes);
    }
    for(i = 0; i < size; i++)
    {
      printf("%15s\t%5d\t%5d\t%5d\t%5d\t%15s\t%2s\n", p[i].name, p[i].runs, p[i].wickets, p[i].catchesTaken, p[i].catchesDropped, p[i].role, p[i].specDes);
    }
}
