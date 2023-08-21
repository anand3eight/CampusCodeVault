//Division of Sum of Pairs

#include<stdio.h>

int pairsum(int *p, int val, int len)
{
    int i, j = 1;
    for(i = 0; i < len; i++)
    {

        if(j < len)
        {
            if((*(p+i) + *(p+j))%val == 0)  return 1;
            i--;
            j++;
        }
        else j = i + 2;
    }
    return 0;
}
void main()
{
    int len, i;
    printf("Enter Length : ");
    scanf("%d", &len);
    int arr[len];
    printf("Enter Array Elements : ");
    for(i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Divisor Value : ");
    scanf("%d", &i);
    if(pairsum(arr, i, len) == 1)   printf("True");
    else printf("False");
}
