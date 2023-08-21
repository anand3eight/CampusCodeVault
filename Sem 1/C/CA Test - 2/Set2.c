/* Maximum K-Product */

#include<stdio.h>

int arr[10];
int kProduct(int start, int k)
{
    int i, j, pdt = 1;
    for(i = start; i < start + k; i++)
    {
        pdt *= arr[i];
    }
    return pdt;
}
int maxProduct(int size, int k)
{
    int i, j, max = 0;
    for(i = 0; i < size-k; i++)
    {
        for(j = i + 1; j < size; j++)
        {
          if(max < arr[i]*kProduct(j, k-1))  max = arr[i]*kProduct(j, k-1);
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
    int size, k;
    printf("Enter the Size : ");
    scanf("%d", &size);
    inputArr(size);
    printf("Enter the Value for K : ");
    scanf("%d", &k);
    printf("Max = %d", maxProduct(size, k));
}
