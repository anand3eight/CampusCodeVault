/* Minimum Number of Swaps To
Group All 1's together In a Binary Array Using Window Sliding
Approach */

#include<stdio.h>

void main()
{
  int size;
  printf("Enter The Array Size : ");
  scanf("%d", &size);
  int arr[size], i;
  //Input of Array Elements
  printf("Enter The Binary Array :\n");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
  //Counting Number Of Ones
  int numberOfOnes = 0;
  for(i = 0; i < size; i++)
  {
      if(arr[i] == 1)   numberOfOnes++;
  }
  //Counting Ones in The First Sub Array Of Length of numberOfOnes
  int x = numberOfOnes;
  int countOnes = 0, maxOnes;
  for(i = 0; i < x; i++)
  {
      if(arr[i] == 1)  countOnes++;
  }
  //Calculating Max Number Of Ones In Each subArray
  //using Window Sliding Technique
  maxOnes = countOnes;
  for(i = 1; i < size - x + 1; i++)
  {
      if(arr[i-1] == 1)   countOnes--;
      if(arr[i+x-1] == 1) countOnes++;
      if(maxOnes < countOnes)  maxOnes = countOnes;
  }
  //Solved Using Nested Loop
  /*int countOnes[size - numberOfOnes];
  int j;
  for(i = 0; i <= size - numberOfOnes; i++)
  {
      countOnes[i] = 0;
      for(j = i; j < i + numberOfOnes; j++)
      {
          if(arr[j] == 1)
              countOnes[i]++;
      }
  }
  int maxOnes = countOnes[0];
  for(i = 0; i <= size - numberOfOnes; i++)
      {
          if(countOnes[i] > maxOnes)
            maxOnes = countOnes[i];
      }
  */
  int numberOfZeros = numberOfOnes - maxOnes;
  printf("Ans = %d", numberOfZeros);
}
