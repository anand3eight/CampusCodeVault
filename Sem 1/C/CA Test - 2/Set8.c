/* ORMax Problem */

#include<stdio.h>
int arr[20];
void inputArr(int size)
{
  int i;
  printf("Enter Array :\n");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
}
void main()
{
    int size;
    printf("Enter size : ");
    scanf("%d", &size);
    inputArr(size);
    int validPairCount = 0;
    int i, j, a, b, max;
    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            a = arr[i];
            b = arr[j];
            max = a > b ? a : b;
            if((a|b) <= max)
                validPairCount++;
        }
    }
    printf("Valid Pairs = %d", validPairCount);
}
