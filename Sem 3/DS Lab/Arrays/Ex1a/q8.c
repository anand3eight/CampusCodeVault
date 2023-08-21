//Peak Element of an Array

#include<stdio.h>
#include<stdlib.h>

int PeakElement(int *arr, int len)
{
	int i;
	for(i = 1; i < len - 1; i++)
	{
		if((*(arr + i) > *(arr + i - 1)) && (*(arr + i) > *(arr + i + 1)))
			return i;
	}
	return -1;
}

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
	int peak = PeakElement(arr, len);
	if(peak != -1)
		printf("Peak Element Index is %d \nElement is %d", peak, arr[peak]);
	else
		printf("None");

}
