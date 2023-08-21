/* Maximum Product of abs(i-j)*min(arr[i], arr[j]) */

#include<stdio.h>
#include<stdlib.h>
int arr[20];
int min(int n1, int n2)
{
    if(n1 < n2) return n1;
    return n2;
}
int maxProduct(int size)
{
    int i, j, max = 0;
    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(max < (abs(i-j) * min(arr[i], arr[j])))
                max = abs(i-j) * min(arr[i], arr[j]);
        }
    }
    return max;
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
    printf("Enter Size : ");
    scanf("%d", &size);
    inputArr(size);
    printf("Max = %d", maxProduct(size));
}
