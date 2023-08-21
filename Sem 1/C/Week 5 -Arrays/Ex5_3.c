/* Adjacent Stick Game */

#include<stdio.h>

void main()
{
    int size;
    printf("Enter The Array Size : ");
    scanf("%d", &size);
    int arr[size], i;
    int sum = 0;
    printf("Enter Array : ");
    for(i = 0; i < size; i++)
        {
          scanf("%d", &arr[i]);
        }
    for(i = 0; i < size; i += 2)
        {
          sum += arr[i] < arr[i+1] ? arr[i] : arr[i+1];
        }
    printf("Sum = %d", sum);
}
