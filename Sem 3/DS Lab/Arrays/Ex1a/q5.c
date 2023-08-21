//Square Array Elements

#include<stdio.h>
#include<math.h>
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
	for(i = 0; i < len; i++)
	{
		printf("%d ", (int)pow(*(arr + i), 2));
	}
}
