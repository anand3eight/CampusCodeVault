/* Count Odd And even Elements In An Array */

#include<stdio.h>

void main()
{
  int size;
  printf("Enter The Array Size : ");
  scanf("%d", &size);
  int arr[size], i;
  //Input of Array Elements
  printf("Enter The Array :\n");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
  int even = 0, odd = 0;
  for(i = 0; i < size; i++)
  {
      if(arr[i]%2 == 0)    even++;
      else  odd++;
  }
  printf("Even Elements = %d", even);
  printf("\nOdd Elements = %d", odd);
}
