// Spiral Pattern

#include <stdio.h>

void main()
{
      int row, col, i, j;
      printf("Enter Row and Column : ");
      scanf("%d %d", &row, &col);
      int arr[row][col];
      printf("Enter Elements : ");
      for(i = 0; i < row; i++)
      {
          for(j = 0; j < col; j++)
          {
              scanf("%d", &arr[i][j]);
          }
      }
      int k = 0, l = row-1, m = 0, n = col-1;
      while(k <= l && m <= n)
      {
        for(i = m; i <= n; i++)
        {
            printf("%d ", arr[k][i]);
        }
        k++;
        for(i = k; i <= l; i++)
        {
            printf("%d ", arr[i][n]);
        }
        n--;
        for(i = n; i >= m; i--)
        {
            printf("%d ", arr[l][i]);
        }
        l--;
        for(i = l; i >= k; i--)
        {
            printf("%d ", arr[i][m]);
        }
        m++;
      }


}
