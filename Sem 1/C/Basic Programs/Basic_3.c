/* 3. The distance between two stations is D km.
A train takes t hours to cover this distance. Calculate
the speed of the train in km/hr and m/s.
Get the values of D and t from the user. */

#include <stdio.h>

void main()
{
   float Dist, Time;
   float spdkm, spdmtr;
   printf("Enter The Distance Between Two stations in kms : ");
   scanf("%d", &Dist);
   printf("Enter The Time Taken For Travel in Hours : ");
   scanf("%d", &Time);
   spdkm = Dist / Time;
   spdmtr = (Dist * 1000) / (Time * 3600);
   printf("\nSpeed In Km/Hr = %f", spdkm);
   printf("\nSpeed In M/S = %f", spdmtr);
}
