/* To remove Duplicates in an array */

#include<stdio.h>

void main()
{
    int a[7] = {1, 2, 2, 1, 3, 4, 5};
    int i, j, k, size = 7 ;
    for(i = 0; i < size; i++)
    {
        for(j = i+1; j < size; j++ )
        {
            if(a[i] == a[j])
            {
                for(k = j; k < size-1; k++)
                {
                    a[k] = a[k+1];
                }
              size--;
              j--;
            }
        }
    }
    printf("ARRAY : ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}
