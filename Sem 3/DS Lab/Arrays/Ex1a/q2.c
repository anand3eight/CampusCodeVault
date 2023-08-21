//Transpose of a Matrix

#include<stdio.h>

void main()
{
	int row, col;
	printf("Enter Row and Column : ");
	scanf("%d %d", &row, &col);
	int i, j, arr[row][col];
	printf("Enter Array Elements :\n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for(i = 0; i < col; i++)
	{
		for(j = 0; j < row; j++)
		{
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}
}
