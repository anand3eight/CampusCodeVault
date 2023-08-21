/* Insert Elements in an Array */

#include<stdio.h>
#include<stdlib.h>

void insertArrayElmt(int *p)
{
    int pos;
    printf("Enter a Position : ");
    scanf("%d", &pos);
    printf("Enter the Element : ");
    scanf("%d", p + pos);
}

void main()
{
    int *p, size;
    printf("Enter Size of An Array : ");
    scanf("%d", &size);
    p = (int *)malloc((size-1) * sizeof(int));
    int i;
    for(i = 0; i < size-1; i++)
    {
        insertArrayElmt(p);
    }
    for(i = 0; i < size-1; i++)
    {
        printf("%d ", *(p + i));
    }
}
