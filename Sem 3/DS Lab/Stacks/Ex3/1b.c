//Stack operation - Linked Lists
#include<stdio.h>
#include<stdlib.h>
typedef struct Node Node;

struct Node
{
	int num;
	Node *next;
};

void push(Node **head)
{
	Node *newNode = malloc(sizeof(Node));
	printf("Enter Value : ");
	scanf("%d", &newNode->num);
	newNode->next = *head;
	*head = newNode;
}

void pop(Node **head)
{
	if(*head == NULL)
	{
		printf("Underflow");
		return;
	}
	printf("Pop : %d", (*head)->num);
	Node *temp = *head;
	*head = (*head)->next;
	free(temp);
}

void display(Node **head)
{
	Node *temp;
	printf("Stack : ");
	while(*head != NULL)
	{
		printf("%d ", (*head)->num);
		temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
}

void main()
{
	Node *head = NULL;
	int ch, loop = 1;
	while(loop)
	{
	  printf("1 : Push \n2 : Pop \n3 : Find Top \n4 : Display \n-> ");
	  scanf("%d", &ch);
	  switch(ch)
	  {
		case 1 :
			push(&head);
			break;
		case 2 :
			pop(&head);
			break;
		case 3 :
			printf("Top : %d", head->num);
			break;
		case 4 :
			display(&head);
			break;
		default :
			printf("Invalid Choice");
	  }
	  printf("\nTo End, Press 0 -> ");
	  scanf("%d", &loop);
	}
}
