/* Number to Name */

#include<stdio.h>
#include<math.h>

void name(int n)
{
	switch(n)
	{
		case 1:
		printf("One ");
		break;
		case 2:
		printf("Two ");
		break;
		case 3:
		printf("Three ");
		break;
		case 4:
		printf("Four ");
		break;
		case 5:
		printf("Five ");
		break;
		case 6:
		printf("Six ");
		break;
		case 7:
		printf("Seven ");
		break;
		case 8:
		printf("Eight ");
		break;
		case 9:
		printf("Nine ");
		break;
		default:
		printf("Zero ");
		break;
	}
}
int power(int count)
{
	if(count > 0)	return 10 * power(count-1);
	else return 1;
}
void main()

{
	int num, rem, check;
	printf("Enter a Number : ");
	scanf("%d", &num);
	int count = 0;
  check = num;
	for(rem = 0; num > 0 ; num /= 10 )
	{
		count++;
	}
  num = check;
	for(rem = 0; num > 0; count--)
	{
		rem = num / power(count-1);
    num %= power(count-1);
		name(rem);
	}

}
