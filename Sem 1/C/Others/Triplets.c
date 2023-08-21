/* Triplets sum = 0 */

#include<stdio.h>

void main()
{
    int a[6] = {0, -1, 1, 0, 2, -2};
    int i, j, k;
    int size;
    //To Remove Duplicates
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
    //Triplets Checker
    for(i = 0; i < size; i++)
    {
        for(j = i+1; j < size; j++)
        {
            for(k = j+1; k < size; k++)
            {
              if(a[i] + a[j] + a[k] == 0)
                  printf("[ %d,  %d,  %d]\n",a[i], a[j], a[k]);
                  break;
            }
        }
    }
}
