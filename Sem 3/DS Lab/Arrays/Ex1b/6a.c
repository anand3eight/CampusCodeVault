//Sum of Array using DMA

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int len;
    printf("Enter Array Length : ");
    scanf("%d", &len);
    int *p = (int*)malloc(sizeof(int) * len);
    int i;
    printf("Enter Array Elements : ");
    for(i = 0; i < len; i++)
    {
        scanf("%d", p + i);
    }
    printf("Array Elements : ");
    int sum = 0;
    for(i = 0; i < len; i++)
    {
        sum += *(p + i);
        printf("%d ", *(p + i));
    }
    printf("\nSum = %d", sum);
}
