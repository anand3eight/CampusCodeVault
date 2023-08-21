/* Student Problem */

#include<stdio.h>
#include<stdlib.h>

struct Student
{
    char name[30];
    int mark;
};
void inputArray(struct Student *p)
{
    printf("Enter Name and Mark :\n");
    scanf("%s %d", p->name, &(p->mark));
}

float averageCal(struct Student *p, int n)
{
    int index, total = 0;
    for(index = 0; index < n; index++)
    {
        total += (p+index)->mark;
    }
    return total/n;
}

void lesserAverage(struct Student *p, float avg, int n)
{
    int index, m;
    printf("Students Less than Average :\n");
    for(index = 0; index < n; index++)
    {
        m = (p+index)->mark;
        if(m < (int)avg)
            printf("\n%s", (p+index)->name);
    }
}

void highestDisplay(struct Student *p, int n)
{
    int m, index = 0, max = 0;
    for(index = 0; index < n; index++)
    {
        m = (p + index)->mark;
        if(max < m)
            max = m;
    }
    printf("\nMaximum Mark Scorer(s) :");
    for(index = 0; index < n; index++)
    {
        m = (p + index)->mark;
        if(max == m)
            printf("\n%s", (p + index)->name);
    }
}

void main()
{
    struct Student *p;
	  int size;
    printf("Enter The Size : ");
    scanf("%d", &size);
    p = (struct Student *)malloc(size * 34);
    int index;
    for(index = 0; index < size; index++)
    {
        inputArray(p + index);
    }
    printf("Average = %.3f\n", averageCal(p, size));
    lesserAverage(p, averageCal(p,size), size);
    highestDisplay(p, size);

}
