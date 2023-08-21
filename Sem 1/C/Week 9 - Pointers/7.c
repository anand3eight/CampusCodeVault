/* Duplicate Checker */

#include<stdio.h>
#include<stdlib.h>

void inputArrayDupCheck(int *p, int n)
{
	int index, check, num, j;
	for(index = 0; index < n; index++)
	{
		printf("Enter Element %d : ", index + 1);
		check = 0;
		scanf("%d", p + index);
		num = *(p + index);
		for(j = 0; j < index; j++)
		{
			if(num == *(p + j))
			{
				check = 1;
			}
					
		}
		if(check == 0)
		{
			printf("Printing Value %d\n", *(p + index));
		}
		
	}
	printf("Input Successful\n");
}

void main()
{
	int *p, size;
	printf("Enter size : ");
	scanf("%d", &size);
	p = (int *)malloc(size * sizeof(int));
	inputArrayDupCheck(p, size);
}
