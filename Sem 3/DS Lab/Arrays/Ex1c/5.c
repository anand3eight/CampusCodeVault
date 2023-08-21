//Free Function in C

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i;
	int *p = (int*)calloc(sizeof(int),3);
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	printf("Before Free : ");
	for(i = 0; i < 3; i++)
	{
		printf("%d ", p[i]);
	}
	free(p[2]);
	printf("\nAfter Free : ");
	for(i = 0; i < 3; i++)
	{
		printf("%d ", p[i]);
	}
}
