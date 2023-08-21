//Stack Operations-Arrays

#include<stdio.h>
#include<stdlib.h>

int *stack;

void push(int *pos, int len)
{
	if(*pos == len-1)
	{
		printf("\nOverflow");
		return;
	}
	printf("\nEnter Value : ");
	scanf("%d", &stack[++(*pos)]);
}

void pop(int *pos)
{
	if(*pos == -1)
	{
		printf("\nUnderflow");
		return;
	}
	printf("Pop : %d", stack[(*pos)--]);
}

void display(int *pos)
{
	printf("Stack : ");
	while(*pos != -1)
	{
		printf("%d ", stack[(*pos)--]);
	}
}
void main()
{
	int ch, len, loop = 1, pos = -1;
	printf("Enter Length : ");
	scanf("%d", &len);
	stack = (int*)malloc(sizeof(int)*len);
	while(loop)
	{
	  printf("1 : Push \n2 : Pop \n3 : Find Top \n4 : Display \n-> ");
	  scanf("%d", &ch);
	  switch(ch)
	  {
		case 1 :
			push(&pos, len);
			break;
		case 2 :
			pop(&pos);
			break;
		case 3 :
			printf("Top : %d", stack[pos]);
			break;
		case 4 :
			display(&pos);
			break;
		default :
			printf("Invalid Choice");
	  }
	  printf("\nTo End, Press 0 -> ");
	  scanf("%d", &loop);
	}
}
