//Regular Queue using Arrays

#include<stdio.h>
#include<stdlib.h>
int *queue;

void enqueue(int *top, int len)
{
	if(*top == len-1)
	{
		printf("Overflow");
	}
	else
	{
		int val;
		printf("Enter Value : ");
		scanf("%d", &val);
		queue[++(*top)] = val;
	}
}

void dequeue(int *top)
{
	if(*top == -1)
	{
		printf("Underflow");
	}
	else
	{
		int i;
		printf("\nDequeue : %d", queue[0]);
		for(i = 0; i < (*top); i++)
		{
			queue[i] = queue[i+1];
		}
		(*top)--;
	}
}

void display(int *top)
{
	int i;
	printf("Queue : ");
	for(i = 0; i < (*top)+1; i++)
	{
		printf("%d ", queue[i]);
	}
	*top = -1;
}

void main()
{
	int len, ch, loop = 1, top = -1;
	printf("Enter Length : ");
	scanf("%d", &len);
	queue = (int*)malloc(sizeof(int) * len);
	while(loop != 0)
	{
		printf("\n1 : Enqueue \n2 : Dequeue \n3 : Display \n4 : Delete\nEnter Choice \n->");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 :
				enqueue(&top, len);
				break;
			case 2 :
				dequeue(&top);
				break;
			case 3 :
				display(&top);
				break;
			case 4 :
				free(queue);
				top = -1;
				printf("\nDeleted Queue Successfully");
				break;
			default :
				printf("\nInvalid Choice");
		}
			printf("\nTo End : Press 0 -> ");
			scanf("%d", &loop);
	}
	
}
	

