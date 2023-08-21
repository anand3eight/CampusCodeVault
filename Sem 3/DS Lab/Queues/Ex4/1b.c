//Queues using Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node
{
	int num;
	Node *next;
};

void enqueue(Node **front, Node **rear)
{
	Node *newNode = malloc(sizeof(Node));
	printf("Enter Value : ");
	scanf("%d", &(newNode->num));
	newNode->next = NULL;
	if(!*front)
	{
		*front = newNode;
		*rear = newNode;
		return;
	}
	(*rear)->next = newNode;
	(*rear) = newNode;

}
void dequeue(Node **front)
{
	if(*front)
	{
		Node *temp = *front;
		printf("\nDequeue : %d", (*front)->num);
		if((*front)->next)
			(*front) = (*front)->next;
		free(temp);
		return;
	}
	printf("Underflow");

}

void display(Node **front)
{
	Node *temp;
	printf("\nQueue : ");
	while(*front)
	{
		temp = *front;
		printf("%d ", (*front)->num);
		if(!(*front)->next)
			return;
		(*front) = (*front)->next;
		free(temp);
	}
}

void main()
{
	Node *front = NULL, *rear = NULL;
	int ch, loop = 1;
	while(loop != 0)
	{
		printf("\n1 : Enqueue \n2 : Dequeue \n3 : Display \nEnter Choice \n->");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 :
				enqueue(&front, &rear);
				break;
			case 2 :
				dequeue(&front);
				break;
			case 3 :
				display(&front);
				break;
			default :
				printf("\nInvalid Choice");
		}
			printf("\nTo End : Press 0 -> ");
			scanf("%d", &loop);
	}
}
