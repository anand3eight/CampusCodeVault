/* Mileage Calculator */

#include<stdio.h>

float mileage(float odo1, float odo2, float fuel1, float fuel2)
{
    return (odo2 - odo1)/(fuel1 - fuel2);
}

void main()
{
    float odo1, odo2, fuel1, fuel2;
    printf("Enter Odometer And Fuel Readings at Start : ");
    scanf("%f%f", &odo1, &fuel1);
    printf("Enter Odometer And Fuel Readings at End : ");
    scanf("%f%f", &odo2, &fuel2);
    printf("Mileage = %.2f", mileage(odo1, odo2, fuel1, fuel2));
}
