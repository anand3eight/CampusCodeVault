//Matrix multiplication

#include<stdio.h>

void main()
{
	int arr1[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	int arr2[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	int pdt[3][3];
	int count, i = 0, j = 0, k = 0;
	for(count = 0; count < 9; count++)
		{
			pdt[i][j] = arr1[i][j] * arr2[j][k] + arr1[i][j + 1] * arr2[j + 1][k] + arr1[i][j + 2] * arr2[j+2][k];
			printf("%d ", pdt[i][j]);
			j = 0;
			if(count % 3 == 2)
			{
				k = 0;
				i += 1;
				printf("\n");
			}
			else k += 1;
		}
}
