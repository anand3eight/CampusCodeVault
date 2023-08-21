/* Salvage Value Calculator */

#include<stdio.h>

float dip(float price, float yearOfService, float dipValue)
{
  if(price > (dipValue * yearOfService))
    return price - (dipValue * yearOfService);
  else
    return 0;
}

void main()
{
    float price, yearOfService, dipValue;
    printf("Enter Purchase Price, Year Of Service and Depreciation values(per year) : ");
    scanf("%f%f%f", &price, &yearOfService, &dipValue);
    printf("Salvage Value = %.2f", dip(price, yearOfService, dipValue));
}
