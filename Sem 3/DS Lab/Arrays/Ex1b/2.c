//Missing Number and Repeating Number

#include<stdio.h>


void main()
{
	int *p, i, j, len, temp;
	printf("Enter Array Length : ");
	scanf("%d", &len);
	p = (int)malloc(len*sizeof(int));
	printf("Enter Array Elements : ");
	for(i = 0; i < len; i++)
	{
		scanf("%d", p + i);
	}
	
	int *count = (int*)calloc(len, sizeof(int));
	for(i = 0; i < len; i++)
	{
		*(count + *(p + i)) += 1;
	}
	
	for(i = 1; i <= len; i++)
	{
		if (*(count + i) > 1)		printf("\nRepeat : %d", i);
		if (*(count + i) == 0)		printf("\nMiss : %d", i);
	}
}
