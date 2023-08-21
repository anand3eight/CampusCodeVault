/* Step Counter */

#include<stdio.h>

void main()
{
    int startX, reachX, startY, reachY;
    printf("Enter Start Co-ordinates : ");
    scanf("%d%d", &startX, &startY);
    printf("Enter Reach Co-Ordinates : ");
    scanf("%d%d", &reachX, &reachY);
    printf("Directions :\nNorth = 1\nSouth = 2\nEast = 3\nWest = 4");
    int StepCount, direction;
    for(StepCount = 0;; StepCount++)
    {
      if((startX == reachX) && (startY == reachY))
        break;
        printf("\nEnter Direction : ");
        scanf("%d", &direction);
        switch(direction)
        {
            case 1:
              startY++;
              break;
            case 2:
              startY--;
              break;
            case 3:
              startX++;
              break;
            case 4:
              startX--;
              break;
            default:
              printf("Enter Proper Value");

        }


    }
    printf("\nDestination Reached in %d steps", StepCount);

}
