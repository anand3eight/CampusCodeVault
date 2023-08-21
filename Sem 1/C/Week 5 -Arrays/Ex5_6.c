/* Employee Wages Problem */

#include<stdio.h>

void main()
{
    long int empId[7];
    int hours[7];
    double payRate[7], wages[7];
    int i;
    printf("Enter Details : ");
    for(i = 0; i < 7; i++)
        {
          printf("\nEmployee ID : ");
          scanf("%d", &empId[i]);
          printf("Hours Worked : ");
          scanf("%d", &hours[i]);
          printf("Pay Rate : ");
          scanf("%lf", &payRate[i]);
          wages[i] = hours[i] * payRate[i];

        }
    printf("empId   \tWages");
    for(i = 0; i < 7; i++)
    {
      printf("\n%d %.2lf", empId[i], wages[i]);
    }


}
