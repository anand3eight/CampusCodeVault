/* Longest Decreasing Subsequence */

#include<stdio.h>

void main()
{
    int arr[7] = {1, 2, 4, 6, 5, 4, 3};
    int lds[7];
    int i, j;
    lds[0] = 1;
    for(i = 1; i < 7; i++)
    {
        lds[i] = 1;
        for(j = 0; j < i; j++)
        {
            if(arr[i] < arr[j]  &&  lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
        }
    }
    int max = lds[0];
    for(i = 0; i < 7; i++)
    {
        if(lds[i] >= max)
            max = lds[i];
        printf("%d ", lds[i]);
    }
    printf("\nMAX = %d", max);

}
