/* Apex Cloud Problem */

#include<stdio.h>

void main()
{
    int hardDisk, ram;
    int plan;
    int price;
    printf("Enter HardDisk and RAM requirements(in GB) : ");
    scanf("%d%d", &hardDisk, &ram);
    printf("PLANS\n1 - Monthly\n2 - HalfYearly\n3 - Yearly\nEnter Plan : ");
    scanf("%d", &plan);
    if(plan == 1)
    {
        if(hardDisk <= 512 && ram <= 4)   price = 500;
        else if(hardDisk > 512 || ram > 4)   price = 1200;
    }
    else if(plan == 2)
    {
        if(hardDisk <= 512 && ram <= 4)   price = 2750;
        else if(hardDisk > 512 || ram > 4)   price = 6600;
    }
    else if(plan == 3)
    {
        if(hardDisk <= 512 && ram <= 4)   price = 5000;
        else if(hardDisk > 512 || ram > 4)   price = 12500;
    }
    printf("FINAL PRICE IS %d", price);

}
