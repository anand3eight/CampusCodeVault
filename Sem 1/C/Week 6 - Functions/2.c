/* Pieces Calculator */

#include<stdio.h>

int pieceCal(int workerCount, int hour)
{
	int pieces;
	if((hour >= 6)	&&	(hour < 10))	return workerCount * 30;
	else if((hour >= 10)	&&	 (hour < 14))	return workerCount * 40;
	else if((hour >= 14)	&&	 (hour < 18))	return workerCount * 35;
}
void main()
{
	int workerCount, hour;
	printf("Enter Number Of Workers and Hour of the Day(24 Hour Clock): ");
	scanf("%d%d", &workerCount, &hour);
	printf("Pieces = %d", pieceCal(workerCount, hour));
}
