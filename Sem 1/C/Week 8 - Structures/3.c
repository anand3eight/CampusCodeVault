/* Shopper's Program */

#include<stdio.h>

struct shopper
{
	int custID, prodID, quantity, unitPrice, totalPrice;
	char prodType;
}sh[10];

void display(int i)
{
	printf("PRINTING DETAILS : ");
	printf("%5d%5c%7d", sh[i].custID, '-', sh[i].totalPrice);
}

void main()
{
	int i, j, size; 
	printf("Enter the Number of Customers : ");
	scanf("%d", &size);
	for(i = 0; i < size; i++)
	{
		printf("Enter Your ID : ");
		scanf("%d", &sh[i].custID);
		printf("Enter Product ID : ");
		scanf("%d", &sh[i].prodID);
		int ch = 1;
		sh[i].totalPrice = 0;
		while(ch == 1)
		{
			printf("Enter Product Type : ");
			scanf("\n%c", &sh[i].prodType);
			printf("Enter Quantity and Unit Price : ");
			scanf("%d%*c%d", &sh[i].quantity, &sh[i].unitPrice);
			switch(sh[i].prodType)
			{
				case 'A' : 
					sh[i].totalPrice += 0.95*(sh[i].quantity * sh[i].unitPrice);
					break;
				case 'B' : 
					sh[i].totalPrice += 0.93*(sh[i].quantity * sh[i].unitPrice);
					break;
				case 'C' : 
					sh[i].totalPrice += 0.88*(sh[i].quantity * sh[i].unitPrice);
					break;
				default : 
					sh[i].totalPrice += 0.98*(sh[i].quantity * sh[i].unitPrice);
			}
			printf("Do You Want to Continue - (1 - yes) : ");
			scanf("%d", &ch);
		}
	}
	for(i = 0; i < size; i++)
	{
		if(sh[i].totalPrice > 10000)
		{
			sh[i].totalPrice -= 500; 
		}
		display(i);
	}
	
}
