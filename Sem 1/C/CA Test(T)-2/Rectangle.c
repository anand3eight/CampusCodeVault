/* Max Rectangle Area Problem */

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
    printf("Enter Array Size : ");
    scanf("%d", &size);
    inputArr(size);
    int i, area[size-1];
    for(i = 0; i < size-1; i++)
    {
        if(arr[i] < arr[i+1])   area[i] = arr[i] * 2;
        else area[i] = arr[i+1] * 2;
    }
    int max = area[0];
    for(i = 1; i < size-1; i++)
    {
        if(max < area[i]) max = area[i];
    }
    printf("Max = %d", max);
}
