/* Bitwise Sum */

#include<stdio.h>
int arr[10];
int BitwiseSum(int a, int b)
{
    return a & b;
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
    printf("Enter size : ");
    scanf("%d", &size);
    inputArr(size);
    int i, j, sum = 0;
    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            sum += BitwiseSum(arr[i], arr[j]);
        }
    }
    printf("Sum = %d", sum);
}
