//Min and Max Elements in an Array

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
	int min = *(arr + 0), max = *(arr + 0);
	for(i = 1; i < len; i++)
	{
		if(min > *(arr + i))
		{
			min = *(arr + i);
			continue;
		}
		if(max < *(arr + i))
			max = *(arr + i);
	}
	printf("Min = %d \nMax = %d", min, max);

}
