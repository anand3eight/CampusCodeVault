/* Weather Checker */

#include<stdio.h>

int weather(int temp)
{
	if(temp > 25)	printf("HOT");
	else if(temp > 10)	printf("MILD");
	else if(temp < 10)	printf("COLD");
}
void main()
{
	int temp;
	printf("Enter a Temperature : ");
	scanf("%d", &temp);
	weather(temp);
}
