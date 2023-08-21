/* Sorting Array Of Pointers */

#include<stdio.h>

void main()
{
	int index, *p[5], a[5] = {1, 2, 3, 4, 5};
	for(index = 0; index < 5; index++)
	{
		p[index] = &a[index]; 
	}
	int temp, j;
	for(index = 0; index < 4; index++)
	{
		for(j = 0; j < index; j++)
		{
			if(*p[j] < *p[index])
			{
				temp = *p[j];
				*p[j] = *p[index];
				*p[index] = temp;
			}
		}
	}
	for(index = 0; index < 5; index++)
	{
		printf("%d\n", p + index);
	}
}
