/* IntereChange of 4 X 4 Matrix */

#include<stdio.h>

int arr[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

void arrSwap(int (*p)[4])
{
    int i, j, temp;
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 4; j++)
        {
            temp = *(*(p + i) + j);
            *(*(p + i) + j) = *(*(p + i + 2) + j);
            *(*(p + i + 2) + j) = temp;
        }
    }
}

void main()
{
    int (*p)[4], i, j;
    p = arr;
    arrSwap(p);
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}
