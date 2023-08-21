/* 3. Write C program to input a temperature in Celsius, then print the temperature value in Celsius
together with one of the following messages:
"COLD" if -40 <= C < 10
"COMFORTABLE" if 10 <= C < 20
"HOT" if 20 <= C < 50
"OUT OF RANGE" if C < -40 or C >= 50 */

#include<stdio.h>

void main()
{
	float temp ;
	printf("Enter The Temperature : ");
	scanf("%f", &temp );
	if( temp >= -40 && temp < 10)
  {
    printf("COLD : %.2f ", temp);
  }
  else if( temp >= 10 && temp < 20)
    {
      printf("COMFORTABLE : %.2f ", temp);
    }
  else if( temp >= 20  && temp < 50)
    {
      printf("HOT : %.2f ", temp);
    }
  else
  {
      printf("OUT OF RANGE : %.2f", temp );
  }
}
