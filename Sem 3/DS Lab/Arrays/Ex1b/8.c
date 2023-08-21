//Sum of n Numbers


#include<stdio.h>

int addUpton(int n)
{

	return n*(n+1)/2;
}
void main()
{
	int num;
	printf("Enter Number : ");
	scanf("%d", &num);
	printf("Sum upto n : %d", addUpton(num));
}
