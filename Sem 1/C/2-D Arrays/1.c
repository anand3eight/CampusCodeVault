/* Transpose of a Matrix */

#include<stdio.h>

void main()
{
      int r, c;
      printf("Enter The Array Size(Row, Column) : ");
      scanf("%d%d", &r, &c);
      int arr[r][c], transpose[c][r], row, col, temp;
      printf("Enter Array :\n");
      for(row = 0; row < r; row++)
      {
        for(col = 0; col < c; col++)
        {
          scanf("%d", &arr[row][col]);
        }
      }
      for(row = 0; row < r; row++)
      {
        for(col = 0; col < c; col++)
        {
          printf("%d\t", arr[row][col]);
        }
        printf("\n");
      }
      printf("\n");
      for(row = 0; row < r; row++)
      {
        for(col = 0; col < c; col++)
        {
            transpose[col][row] = arr[row][col];
        }
      }
      for(row = 0; row < c; row++)
      {
        for(col = 0; col < r; col++)
        {
          printf("%d\t", transpose[row][col]);
        }
        printf("\n");
      }
}
