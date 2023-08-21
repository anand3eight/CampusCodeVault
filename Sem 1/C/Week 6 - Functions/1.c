/* fibonacci Series with Golden Ratio */

#include<stdio.h>

void fibo(int n)
{
	float f1 = 1, f2 = 1;
	float f3;
	int i;
	float goldenRatio;
	for(i = 1; i <= n; i++)
	{
		f3 = f1 + f2;
		goldenRatio = f1/f2;
		printf("(%.2f, %.2f, %.2f)",f1, f2, goldenRatio);
		f1 = f2;
		f2 = f3;
	}
}
void main()
{
	int num;
	printf("Enter A Number : ");
	scanf("%d", &num);
	fibo(num);
}

