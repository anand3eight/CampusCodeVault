//Deque using LinkedList

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node
{
	int num;
	Node *next;
};

void insertFirst(Node **front, Node **rear)
{
	Node *newNode = malloc(sizeof(Node));
	printf("Enter Value : ");
	scanf("%d", &(newNode->num));
	newNode->next = *front;
	if(!*front)
		(*rear) = newNode;
	(*front) = newNode;
}

void insertLast(Node **front, Node **rear)
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

void deleteFirst(Node **front, Node **rear)
{
	if(*front)
	{
		printf("\nDequeue : %d", (*front)->num);
		if(*front == *rear)
		{
				*front = *rear = NULL;
				return;
		}
		Node *temp = *front;
		if(!(*front)->next)
		{
			*front = NULL;
			free(temp);
			return;
		}
		(*front) = (*front)->next;
		free(temp);
		return;
	}
	printf("Underflow");

}

void deleteLast(Node **front, Node **rear)
{
	if(!*front)
	{
		printf("UnderFlow");
		return;
	}
	if(*front == *rear)
	{
		printf("Dequeue : %d", (*rear)->num);
		*front = *rear = NULL;
		return;
	}
	Node *temp = *front;
	while(temp->next != *rear)
	{
		temp = temp->next;
	}
	printf("Dequeue : %d", (*rear)->num);
	(*rear) = temp;
	free(temp->next);
}

void display(Node **front, Node **rear)
{
	Node *temp;
	printf("\nQueue : ");
	while(*front)
	{
		deleteFirst(front, rear);
	}
}

void main()
{
	Node *front = NULL, *rear = NULL;
	int ch, loop = 1;
	while(loop != 0)
	{
		printf("\n1 : InsertFirst \n2 : InsertLast \n3 : DeleteFirst \n4 : DeleteLast \n5 : Display \nEnter Choice \n->");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 :
				insertFirst(&front, &rear);
				break;
			case 2 :
				insertLast(&front, &rear);
				break;
			case 3 :
				deleteFirst(&front, &rear);
				break;
			case 4 :
				deleteLast(&front, &rear);
				break;
			case 5 :
				display(&front, &rear);
				break;
			default :
				printf("\nInvalid Choice");
		}
			printf("\nTo End : Press 0 -> ");
			scanf("%d", &loop);
	}
}
