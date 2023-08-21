/* 2. Write C program to calculate the water bill for consumers
of a certain city. The input is given
as the consumer ID number, consumer code
 (D for domestic, I for industrial), the previous
reading of the meter in m3, and the present reading
of the meter in m3.
For consumption up to 100 m3, the rate is 8.000 TL/m3
for domestic consumers, and 12.500
TL/m3 for industrial consumers. If the consumption
is more than 100 m3, the rate is 30% more
than the normal rate for the exceeding amount.
Output the consumer ID with his total bill in TL, including 12% VAT */

#include<stdio.h>

void main()
{
	int cust_id;
	int cust_code;
	float prevreading, newreading, netreading, newtotal, vat ;
	printf("Enter Your Customer ID, \nCustomer Code (1 - Domestic/2 - Industry), \nPrevious Reading, \nPresent Reading : ");
	scanf("%d%d%f%f", &cust_id, &cust_code, &prevreading, &newreading);
  netreading = newreading - prevreading ;
  if( cust_code == 1)
	{
		newtotal = netreading * 8.000 ;
	}
	else
	{
		newtotal = netreading * 12.500;
	}
	if( netreading > 100 )
	{
		newtotal += 0.30*newtotal;
	}
	vat = 0.12 * newtotal ;
	newtotal += vat ;
  printf("\nCustomer ID : %d ", cust_id);
	printf("\nTotal Cost = %.3f ", newtotal);
}
