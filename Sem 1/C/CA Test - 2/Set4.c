/* Find the Smallest Positive Integer in an Array */

#include<stdio.h>
int arr[20];
int smallestPositive(int size)
{
    int i, smallestPositive = 1;
    for(i = 0; i < size; i++)
    {
        if(arr[i] > 0 && arr[i] == smallestPositive)
        {
            smallestPositive++;
        }
    }
    return smallestPositive;
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
    printf("Enter the Size : ");
    scanf("%d", &size);
    inputArr(size);
    printf("Smallest Missing Number = %d", smallestPositive(size));
}
