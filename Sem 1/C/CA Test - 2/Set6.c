/* LCM SubArray Problem */

#include<stdio.h>

int arr[15];

int lcmcal(int n1, int n2)
{
    int max = (n1 > n2) ? n1 : n2;
    while(1)
    {
        if((max % n1 == 0)  &&  (max % n2 == 0))
            return max;
        max++;
    }
}
int maxlen(int size)
{
    int i, j, k, lcm, pdt, maxlength = 1, finalMax = 1;
    for(i = 0; i < size; i++)
    {
        maxlength = 1;
        lcm = arr[i];
        pdt = arr[i];
        for(j = i + 1; j < size; j++)
        {
            lcm = lcmcal(lcm, arr[j]);
            pdt *= arr[j];
            if(lcm == pdt)  maxlength++;
        }
        finalMax = finalMax > maxlength ? finalMax : maxlength;
    }
    return finalMax;
}

void inputArr(int size)
{
  int i;
  printf("Enter Array :\n");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
}

void main()
{
    int size;
    printf("Enter size : ");
    scanf("%d", &size);
    inputArr(size);
    printf("Max Length = %d", maxlen(size));
}
