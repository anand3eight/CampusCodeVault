/* Binary Search */

#include<stdio.h>

int binarySearch(int arr[], int i, int len, int x)
{
    int mid;
    if(len >= 1)
    {
      mid = i + (len-1)/2;
      printf("%d %d\n", arr[mid], len);
      if(arr[mid] == x)   return mid;
      if(arr[mid] > x)    return binarySearch(arr, i, mid - 1, x);
      return binarySearch(arr, mid + 1, len, x);
    }
    return -1;
}
void main()
{
    int arr[10], num, size;

    printf("Enter Array Size : ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter an Element : ");
    scanf("%d", &num);
    printf("Index is %d", binarySearch(arr, 0, size - 1, num));
    printf("\n-1 implies Element not Found");
}
