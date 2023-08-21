/* Min, Max and Sum of an Array */

#include<stdio.h>
#include<stdlib.h>

void inputArray(int *p, int n)
{
	int index;
	printf("Enter Elements : ");
	for(index = 0; index < n; index++)
	{
		scanf("%d", p + index);
	}
	printf("Input Successful\n");
}

void maxArray(int *p, int n)
{
	int index, max = *p;
	for(index = 1; index < n; index++)
	{
		if(max < *(p + index))	max = *(p + index);
	}
	printf("Max = %d\n", max);
}

void minArray(int *p, int n)
{
	int index, min = *p;
	for(index = 1; index < n; index++)
	{
		if(min > *(p + index))	min = *(p + index);
	}
	printf("Min = %d\n", min);
}

void sumArray(int *p, int n)
{
	int index, sum = 0;
	for(index = 0; index < n; index++)
	{
		sum += *(p + index);
	}
	printf("Sum = %d", sum);
}

void main()
{
	int *p, size;
	printf("Enter Size of Array : ");
	scanf("%d", &size);
	p = (int*)malloc(size * sizeof(int));
	inputArray(p, size);
	minArray(p, size);
	maxArray(p, size);
	sumArray(p, size);
}
