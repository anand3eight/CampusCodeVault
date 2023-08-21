/* Trace the Least Expensive Path */

#include<stdio.h>

void main()
{
    int arr[4][4] = {999, 1, 999, 2, 1, 1, 9, 1, 1, 999, 5, 999, 1, 1, 1, 1};
    int soX, soY, destX, destY, cost = 0;
    int a, b, c, d;
    int check = 0;
     printf("Enter Source Co-Ordinates : ");
    scanf("%d%*c%d", &soX, &soY);
    printf("Enter Destination Co-Ordinates : ");
    scanf("%d%*c%d", &destX, &destY);
    cost = arr[soX][soY];
    printf("(%d, %d), ", soX, soY);
    while((soX != destX)  || (soY != destY))
    {
        a = 999;
        b = 999;
        c = 999;
        d = 999;
        if(soX != destX)
        {
          if(soX < 3 && check != 1) a = arr[soX+1][soY];
          if(soX > 0 && check != 2) b = arr[soX-1][soY];
        }
        if(soY != destY)
        {
          if(soY < 3 && check != 3) c = arr[soX][soY+1];
          if(soY > 0 && check != 4) d = arr[soX][soY-1];
        }
        if((a < b) && (a < c) && (a < d))
        {
            printf("(%d, %d), ", soX+1, soY);
            cost += arr[soX+1][soY];
            soX += 1;
            check = 2;
        }
        else if((b < a) && (b < c) && (b < d))
        {
            printf("(%d, %d), ", soX-1, soY);
            cost += arr[soX-1][soY];
            soX -= 1;
            check = 1;
        }
        else if((c < a) && (c < b) && (c < d))
        {
            printf("(%d, %d), ", soX, soY+1);
            cost += arr[soX][soY+1];
            soY += 1;
            check = 4;
        }
        else if((d < a) && (d < b) && (d < c))
        {
            printf("(%d, %d), ", soX, soY-1);
            cost += arr[soX][soY-1];
            soY -= 1;
            check = 3;
        }

    }
    printf("\nCost = %d", cost);
}
