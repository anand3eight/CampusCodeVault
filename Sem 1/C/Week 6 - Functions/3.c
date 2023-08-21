/* Base Rate Problem */
#include<stdio.h>

float billAmt(int base, float baseRate)
{
	if((base >= 100)	&&	   (base <= 500))	return(0.05 * base) + baseRate;
	else if((base > 500)	&&	(base <= 1500))	return (0.08 * base) + baseRate;
	else return (2 * base);
}
void main()
{
	int base;
	printf("Enter Base Data : ");
	scanf("%d", &base);
    if((base >= 100)	&&	   (base <= 500))	printf("%.2f", billAmt(base, 0.33*base));
	else if((base > 500)	&&	(base <= 1500))	printf("%.2f", billAmt(base, 1.44*base));
	else printf("%.2f", billAmt(base, 0));
}
