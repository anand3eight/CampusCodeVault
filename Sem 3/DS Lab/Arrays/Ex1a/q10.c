//Weighted Average of a Number


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
	float sum = 0;
	for(i = 0; i < len; i++)
	{
		sum += *(arr + i) * (i + 1);
	}
	printf("%.2f", sum/len);

}
