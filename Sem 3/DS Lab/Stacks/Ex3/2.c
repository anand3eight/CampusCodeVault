//Frequency of Characters

#include<stdio.h>
#include<stdlib.h>

void check(char str[], char *unq, int *count, int ind)
{
	int i, ch = 0;
	for(i = 0; unq[i] != '\0'; i++)
	{
		if(str[ind] == unq[i])
		{
			count[i]++;
			ch = 1;
		}	
	}
	if(!ch)
	{
		unq[i] = str[ind];
		count[i] = 1;
		unq[i+1] = '\0';
	}
}

void pop(char str[], char *unq, int *count, int *top)
{
	while(*top != -1)
	{
		check(str, unq, count, *top);
		(*top)--;
	}
}

void display(char *unq, int *count)
{
	int i;
	for(i = 0; unq[i] != '\0'; i++)
	{
		printf("\n%c Occurs %d Times", unq[i], count[i]);
	}
}
void main()
{
	char str[100];
	printf("Enter String : ");
	scanf("%s", str);
	int top = -1;
	for(top = 0; str[top] != '\0'; top++);
	top--;
	char *unq  = (char*)malloc(sizeof(char)*top);
	unq[0] = '\0';
	int *count = (int*)calloc(sizeof(int), top);
	pop(str, unq, count, &top);
	display(unq, count);
}
