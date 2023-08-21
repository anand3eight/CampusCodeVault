//Mean of Array Elements

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int len;
	printf("Enter Array Length : ");
	scanf("%d", &len);
	int i;
	int *arr = (int*)malloc(len * sizeof(int));
	float sum = 0;
	printf("Enter Array Elements :\n");
	for(i = 0; i < len; i++)
	{
		scanf("%d", arr + i);
		sum += *(arr + i);
	}
	printf("Mean = %.2f", sum/len);

}
