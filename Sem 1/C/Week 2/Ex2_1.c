/* EXERCISE – 2
Conditional Control Constructs - Branching
1. In a certain theatre where tickets normally
cost 2 million TL each, there is a 20% discount if
one person buys more than 15 tickets. Students get
an extra 5% discount. Input the necessary
information. Write C program to check if a discount
is necessary and output the total amount
he must pay. */

#include<stdio.h>

void main()
{
	int oneticket = 2, no_of_tickets, discount, total, stud_dis = 0 ;
	int role;
	printf("Enter Number Of Tickets and Your Role (1 - Student/2 - Others) : ");
	scanf("%d%d", &no_of_tickets, &role );
	total = (no_of_tickets*oneticket) ;
	if( no_of_tickets >= 15)
	{
		discount = 0.20*total;
		total -= discount ;
	}
	if( role == 1 );
	{
		stud_dis = 0.05*total ;
		total -= stud_dis;
	}
	printf("\nTotal Cost = %d ", total);
}
