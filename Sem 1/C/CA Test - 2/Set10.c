/* Active Cells Count */

#include<stdio.h>

int arr[10];

void inputArr(int size)
{
  int i;
  printf("Enter Array :\n");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
}

void cellChanger(int size)
{
    int i, temp[10], pre, post;
    for(i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    for(i = 0; i < size; i++)
    {
        if(i == 0)  pre = 1;
        else        pre = temp[i-1];
        if(i == size-1)   post = 1;
        else              post = temp[i+1];
        if(pre == post)   arr[i] = 0;
        else              arr[i] = 1;
    }
}
int main()
{
  int i, size, daySize, activeCount = 0;
  printf("Enter size : ");
  scanf("%d", &size);
  if(size > 3)  inputArr(size);
  else  return 0;
  printf("Enter Number Of Days : ");
  scanf("%d", &daySize);
  for(i = 0; i < daySize; i++)
  {
      cellChanger(size);
  }
  for(i = 0; i < size; i++)
  {
      if(arr[i] == 1)   activeCount++;
  }
  printf("Active Cells = %d", activeCount);
  printf("\nInactive Cells = %d", size - activeCount);
}
