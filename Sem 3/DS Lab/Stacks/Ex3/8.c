//Sorting a Stack

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *stack, *temp, i, l, top1 = -1, top2 = -1;
    printf("Length : ");
    scanf("%d", &l);
    stack = (int *)malloc(sizeof(int) * l);
    temp  = (int *)malloc(sizeof(int) * l);
    printf("Enter Values : ");
    for(i = 0; i < l; i++)
    {
        scanf("%d", &stack[++top1]);
    }
    while(top1 != -1)
    {
        i = stack[top1--];
        while(top2 != -1 && i < temp[top2])
        {
            stack[++top1] = temp[top2--];
        }
        temp[++top2] = i;
    }
    while(top1 != l-1)
    {
        stack[++top1] = temp[top2--];
    }
    printf("Sorted Stack : ");
    while(top1 != -1)
    {
        printf("%d ", stack[top1--]);
    }
}
