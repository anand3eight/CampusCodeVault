/* Additive Sequence */

#include<stdio.h>

void main()
{
    char num[10];
    printf("Enter Number : ");
    scanf("%s", num);
    int index;
    for(index = 0; num[index] != '\0'; index++);
    if(index < 3)   printf("NOT POSSIBLE TO CHECK");
    else
    {
        int check = 1;
        for( index -= 1; index > 1; index--)
        {
            if((int)num[index]-48 == (int)num[index-1]-48 + (int)num[index-2]-48)
                check = 1;
            else
                check = 0;
                break;
            printf("Check %d", index);
        }
        if(check == 1)  printf("Additive Sequence");
        else  printf("Not An Additive Sequence");
    }
}
