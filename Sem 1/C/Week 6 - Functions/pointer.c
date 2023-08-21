/* To Print Address using Pointers */
#include<stdio.h>
void pointer(int *p)
{
	printf("%p\n", p);
	printf("%d", *p);
}
void main()
{
	int x = 20;
	pointer(&x);
}
