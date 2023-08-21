#include<stdio.h>

int main()
{
	int arr[5];
	int *ptr = &arr;
	printf("%d", sizeof(*ptr));
	return 0;
	
}
