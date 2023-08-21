//Intersection of Sets

#include<stdio.h>

void main()
{
	int arr1[6] = {1, 2, 3, 4, 5, 6};
	int arr2[3] = {1, 3, 5};
	int i, j;
	printf("Intersection Elements : ");
	for(i = 0; i < 6; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(arr1[i] == arr2[j])
			{
				printf("%d ", arr1[i]);
				break;
			}
		}
	}
}
