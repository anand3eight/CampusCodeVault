/* Rearranging Arrays */

#include<stdio.h>
int arr[20];
void sort(int startIndex, int size)
{
  int i, j, temp;
  for(i = startIndex; i < size; i++)
  {
    for(j = i+1; j < size; j++)
    {
        temp = arr[j];
        if(arr[j] <= arr[i])
            {
                arr[j] = arr[i];
                arr[i] = temp;
            }
    }
  }
}
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
  printf("Enter Size Of Array : ");
  scanf("%d", &size);
  inputArr(size);
  int i, j, x, xInd;
  printf("Enter an Element In Array : ");
  scanf("%d", &x);
  for(i = 0; i < size; i++)
  {
      if(arr[i] == x)   break;
  }
  xInd = i;
  sort(xInd, size);
  for(i = 0; i < size; i++)
  {
      if(arr[i] == x)   break;
  }
  xInd = i;
  sort(0, xInd);
  for(i = 0; i < size; i++)
  {
    printf("\n%d", arr[i]);
  }

}
