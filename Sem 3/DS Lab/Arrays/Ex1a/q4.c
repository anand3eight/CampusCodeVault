//Adding Odd Elements in an Array

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int len;
	printf("Enter Array Length : ");
	scanf("%d", &len);
	int i;
	int *arr = (int*)malloc(len * sizeof(int));
	printf("Enter Array Elements :\n");
	for(i = 0; i < len; i++)
	{
		scanf("%d", arr + i);
	}
	int oddsum = 0;
	for(i = 0; i < len; i += 2)
	{
		oddsum += *(arr + i);
	}
	printf("OddSum = %d", oddsum);
}
