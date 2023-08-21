//2-D Array Address Calculation

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int base, size, m, n, x, y, i, j;
	printf("Enter Values for Base, datatype_size, rows, columns, baserow and basecol : ");
	scanf("%d %d %d %d %d %d", &base, &size, &m, &n, &x, &y);
	printf("Enter Position(Row, Column) : ");
	scanf("%d %d", &i, &j);
	int adr = base + size*(m*(j-y) + (i-x));
	printf("Address : %d", adr);
}
