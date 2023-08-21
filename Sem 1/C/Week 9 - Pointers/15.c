/* Merge Sort Using Pointers */
#include<stdio.h>
void mergeSort(int *a, int *b, int *c)
{
  int i = 0, j = 0, k;
  for(k = 0; k < 5 + 5; k++)
  {
    if(*(a + i) < *(b + j))
    {
      *(c + k) = *(a + i);
      i++;
    }
    else
    {
      *(c + k) = *(b + j);
      j++;
    }
  }
}
void main()
{
	int a[5] = {1, 3, 5, 7, 9};
	int b[5] = {2, 4, 6, 8, 10};
	int c[5 + 5];
  int k;
  mergeSort(a, b, c);
	for(k = 0; k < 5 + 5; k++)
	{
		printf("%d ", c[k]);
	}
}
