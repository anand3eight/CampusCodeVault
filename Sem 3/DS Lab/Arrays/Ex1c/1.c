//Array Address Calculation

#include<stdio.h>
#include<stdlib.h>

struct arr
{
	int elmt, adr;
}*p;

void main()
{
	int len, i, search, size = 2;
	printf("Enter Array Length : ");
	scanf("%d", &len);
	p = (struct arr*)malloc(sizeof(struct arr)*len);
	printf("Enter Base Address and First Element : ");
	scanf("%d %d", &p->adr, &p->elmt);
	printf("Enter Array Elements : ");
	for(i = 1; i < len; i++)
	{
		scanf("%d", &(p+i)->elmt);
		(p+i)->adr = p->adr + size*(i- 0);
	}
	printf("Enter Search Element : ");
	scanf("%d", &search);
	for(i = 0; i < len; i++)
	{
		if((p+i)->elmt == search)
		{
			printf("Address of %d is %d", (p+i)->elmt, (p+i)->adr);
		}
	}
}
