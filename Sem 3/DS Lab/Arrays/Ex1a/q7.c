//Reverse an Array

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
	printf("Reversed Array : ");
	for(i = len-1; i >= 0; i--)
	{
		printf("%d ", *(arr + i));
	}

}
