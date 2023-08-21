/* Employee Salary */

#include<stdio.h>

struct salary
{
	int eno;
	char ename[30];
	float basic, netPay;
}sa[10];

void display(int i)
{
	printf("PRINTING DETAILS : ");
	printf("%5d%15s%7.2f", sa[i].eno, sa[i].ename, sa[i].netPay);
}
void main()
{
	int i, j, size; 
	printf("Enter the Number of Employees :\n");
	scanf("%d", &size);
	float DA, HRA, LIC, PF;
	for(i = 0; i < size; i++)
	{
		printf("Enter Details :\n");
		scanf("%d%*c%s%*c%f", &sa[i].eno, sa[i].ename, &sa[i].basic);
		DA = 0.22 * sa[i].basic;
		HRA = 0.12 * sa[i].basic;
		LIC = 0.05 * sa[i].basic;
		PF = 0.12 * sa[i].basic;
		sa[i].netPay = sa[i].basic + DA + HRA + LIC - PF;
	}
	for(i = 0; i < size; i++)
	{
		display(i);
	}
}
