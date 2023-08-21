/* Baby Sitter Problem */

#include<stdio.h>

void main()
{
    double startHour, startMin, endHour, endMin, startTime, endTime;
    double price = 0;
    double startTimeTemp;
    printf("Enter Start Time(in Hours and Minutes) : ");
    scanf("%lf%lf", &startHour, &startMin);
    if(startHour != 12)   startTime = (startHour + 12.0) + (startMin/60.0);
    else    startTime = (startHour - 12.0) + (startMin/60.0);
    printf("Enter End Time(in Hours and Minutes) : ");
    scanf("%lf%lf", &endHour, &endMin);
    if(endHour != 12.0)   endTime = (endHour) + (endMin/60.0);
    else  endTime = (endHour - 12.0) + (endMin/60.0);
    if((startTime >= 18.0) && (startTime <= 21.0))
    {
        startTimeTemp = (21.0 - startTime);
        price += (startTimeTemp * 150.0);
        startTime += startTimeTemp;
    }
    if((startTime >= 21.0) && (endTime >= 0.0))
    {
      price += (3.0 * 100.0);
    }
    if((endTime >= 0.0) && (endTime <= 6.0))
    {
      endTime = (endTime - 0.0);
      price += (endTime * 125.0);
    }
    printf("Price = %.2lf", price);
}
