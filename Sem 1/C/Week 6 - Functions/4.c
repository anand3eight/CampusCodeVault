/* Discount Rate Problem*/

#include<stdio.h>

float discount(float sellingPrice, int weekCount)
{
	if(weekCount >= 3  && weekCount < 4)	return 0.75 * sellingPrice;
	else if(weekCount >= 4  && weekCount < 5)	return 0.50 * sellingPrice;
	else if(weekCount >= 5)		return 0.25 * sellingPrice;
	else if(weekCount <= 3)	return sellingPrice;
}

void main()
{
	float sellingPrice;
	int weekCount;
	printf("Enter Selling Price and Number Of Weeks Passed : ");
	scanf("%f%d", &sellingPrice, &weekCount);
	printf("Price = %.2f", discount(sellingPrice, weekCount));
	
}
