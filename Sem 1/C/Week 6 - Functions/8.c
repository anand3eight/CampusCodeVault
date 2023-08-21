/* Days Calculator */

#include<stdio.h>

int dayYear(int year)
{
    if(year % 4 == 0)
        return 366;
    else
        return 365;
}

int dayMonth(int month)
{
  switch(month)
  {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:
      return 28;
  }
}

void main()
{
    int day, month, year;
    printf("Enter Date Before 1-1-2012 : ");
    scanf("%d%*c%d%*c%d", &day, &month, &year);
    int dayCount = 0;
    dayCount += (32 - day);
    month++;
    for(; month <= 12; month++)
    {
        dayCount += dayMonth(month);
    }
    year++;
    for(; year < 2012; year++)
    {
        dayCount += dayYear(year);
    }
    printf("\nDays = %d", dayCount);
}
