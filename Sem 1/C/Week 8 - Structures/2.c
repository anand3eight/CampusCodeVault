/* Bank Problem */

#include<stdio.h>

struct account
{
	int accno;
	char name[30];
	int deposit, withdrawal;
	char code;	
} c[10], request;

void display(int i)
{
	printf("PRINTING DETAILS :\n");
	printf("%10d%15s%6d\n", c[i].accno, c[i].name, c[i].deposit);
}
void main()
{
	int i, size;
	printf("Enter Number of Customers : ");
	scanf("%d", &size);
	for(i = 0; i < size; i++)
	{
		printf("Enter Details of %d :\n", i+1);
		scanf("%d%*c%s%*c%d", &c[i].accno, c[i].name, &c[i].deposit);
	}
	for(i = 0; i < size; i++)
	{
		if(c[i].deposit < 500)	display(i);
	}
	printf("Enter Request if any : ");
	scanf("%d%*c%s%*c%c", &request.accno, request.name, &request.code);
	for(i = 0; i < size; i++)
	{
		if(c[i].accno == request.accno)
		{
			if(request.code == 'W')
			{
				int withdrawal;
				printf("Enter the Withdrawal Amt : ");
				scanf("%d", &withdrawal);
				if((c[i].deposit - withdrawal) > 500)	c[i].deposit -= withdrawal;
				else	printf("Withdrawal Impossible\n");
			}
			else if(request.code == 'D')
			{
				int dep;
				printf("Enter Deposit Amt : ");
				scanf("%d", &dep);
				c[i].deposit += dep;
			}
		}
	}
	for(i = 0; i < size; i++)
	{
		display(i);
	}
}
