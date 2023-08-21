//Finding kth smallest Elements

#include<stdio.h>

void sort(int *p, int len)
{
    int i, j = 1;
    for(i = 0; i < len; i++)
    {
        if(j < len)
        {
            if(*(p+i) > *(p+j))
            {
                int temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
            i--;
            j++;
        }
        else j = i + 2;
    }
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
  sort(arr, len);
  printf("Enter Search Index : ");
  scanf("%d", &i);
  printf("%d", arr[i-1]);
}
