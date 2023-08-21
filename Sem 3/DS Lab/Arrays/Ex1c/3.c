//2-D Array Address Calculation

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int base, size, m, n, p, x, y, z, i, j, k;
	printf("Enter Values for Base, datatype_size, rows, columns, width, baserow, basecol and basewidth :\n");
	scanf("%d %d %d %d %d %d %d %d", &base, &size, &m, &n, &p, &x, &y, &z);
	printf("Enter Position(Row, Column, Width) : ");
	scanf("%d %d %d", &i, &j, &k);
	int adr = base + size*(m*n*(i-x) + n*(j-y) + (k-z));
	printf("Address : %d", adr);
}
