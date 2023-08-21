/* Bob and Shelly - Rectangle with Sticks */

#include<stdio.h>

void main()
{
  int size;
  printf("Enter The Array Size : ");
  scanf("%d", &size);
  int arr[size], i, j;
  int temp;
  int sub_arr[size/2], sa_index = 0;
  //Getting An Array
  printf("Enter Array : ");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
  //Getting the Duplicate elements as Rectangles have Equal opposite Sides
  for(i = 0; i < size; i++)
  {
      for(j = i+1; j < size; j++)
      {
          if(arr[i] == arr[j])
          {
              sub_arr[sa_index] = arr[i];
              sa_index++;
          }
      }
  }
  //Sorting the Duplicate element Array to get the Largest Values
  for(i = 0; i < sa_index; i++)
  {
    for(j = i+1; j < sa_index; j++)
    {
        temp = sub_arr[j];
        if(sub_arr[j] <= sub_arr[i])
            {
                sub_arr[j] = sub_arr[i];
                sub_arr[i] = temp;
            }
    }
  }
  //Printing the Largest Area
  printf("Area = %d", sub_arr[sa_index-1]*sub_arr[sa_index-2]);
}
