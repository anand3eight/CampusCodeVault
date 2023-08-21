//Duplicate Elements in an Array

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
	
	int *count = (int*)calloc(len, sizeof(int)), sum = 0;
	for(i = 0; i < len; i++)
	{
		*(count + *(p + i)) += 1;
		sum += *(count + *(p + i));
	}
	if(sum < len + 1)
		printf("%d ", -1);
	else
	{
		for(i = 0; i < len; i++)
		{
			if(*(count + i) > 1)
				printf("%d ", i);
		}
	}
	
	
}
