//Circular Queue using Arrays

#include<stdio.h>
#include<stdlib.h>
int *queue;

void enqueue(int *front, int *rear, int len)
{
	if((*rear == len-1 && !*front) || (*rear == *front - 1))
	{
		printf("Overflow");
		return;
	}
	else if(*rear == len - 1 && *front)
		*rear = -1;
	else if(*rear == -1 && *front == -1)
		*front = 0;
	printf("Enter Value : ");
	scanf("%d", &queue[++*(rear)]);
	return;
}

void dequeue(int *front, int *rear, int len)
{
	if(*front == -1)
	{
		printf("\nUnderflow");
		return;
	}
	else if(*rear == *front)
	{
		printf("\nDeQueue : %d", queue[*(front)]);
		*front = *rear = -1;
		return;
	}
	else if(*front == len - 1 )
	{
		printf("\nDeQueue : %d", queue[*(front)]);
		*front = 0;
		return;
	}
	printf("\nDeQueue : %d", queue[(*front)++]);
}

void display(int *front, int *rear, int len)
{
	printf("Queue : ");
	while(*front != -1)
	{
		dequeue(front, rear, len);
	}
}

void main()
{
	int len, ch, loop = 1, front = -1, rear = -1;
	printf("Enter Length : ");
	scanf("%d", &len);
	queue = (int*)malloc(sizeof(int) * len);
	while(loop != 0)
	{
		printf("\n1 : Enqueue \n2 : Dequeue \n3 : Display \nEnter Choice \n->");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 :
				enqueue(&front, &rear, len);
				break;
			case 2 :
				dequeue(&front, &rear, len);
				break;
			case 3 :
				display(&front, &rear, len);
				break;
			default :
				printf("\nInvalid Choice");
		}
			printf("\nTo End : Press 0 -> ");
			scanf("%d", &loop);
	}

}
