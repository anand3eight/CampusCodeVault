//Malloc vs Calloc

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int len;
	printf("Enter Array Length : ");
	scanf("%d", &len);
	int i;
	int *pm = (int*)malloc(sizeof(int)*len);
	int *pc = (int*)calloc(sizeof(int),len);
	printf("Malloc Array : ");
	for(i = 0; i < len; i++)
	{
		printf("%d ", pm[i]);
	}
	printf("\nCalloc Array : ");
	for(i = 0; i < len; i++)
	{
		printf("%d ", pc[i]);
	}
	
}
