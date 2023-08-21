/* Check whether it is a Diagonal Matrix */

#include<stdio.h>

void main()
{
  int r, c;
  printf("Enter The Array Size(Row, Column) : ");
  scanf("%d%d", &r, &c);
  if(r == c)
  {
      int arr[r][c], check = 0, row, col, temp;
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
              if(row != col)
              {
                  if(arr[row][col] == 0)  check = 1;
                  else
                  {
                    check = 0;
                    break;
                  }
              }
          }
          if(check == 0)  break;
      }
      if(check == 1)  printf("DIAGONAL MATRIX");
      else   printf("NOT A DIAGONAL MATRIX");
  }
  else  printf("ERROR");

}
