//Add Two Matrices

#include<stdio.h>

void main()
{
	int row, col;
	printf("Enter Row and Column : ");
	scanf("%d %d", &row, &col);
	int i, j, arr1[row][col], arr2[row][col], sum[row][col];
	printf("Enter Array Elements : format(Arr1 Arr2)\n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			scanf("%d %d", &arr1[i][j], &arr2[i][j]);

		}
	}
	printf("Sum Array :\n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("%d ", arr1[i][j] + arr2[i][j]);

		}
		printf("\n");
	}

}
