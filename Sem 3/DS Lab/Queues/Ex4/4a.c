//Priority Queue using Linked List

#include<stdio.h>
#include<stdlib.h>

int job = 0;
typedef struct Node Node;
struct Node
{
	int p, job;
	Node *next;
};

void enqueue(Node **front, Node **rear)
{
	Node *temp = *front, *newNode = malloc(sizeof(Node));
	printf("Enter Priority : ");
	scanf("%d", &(newNode->p));
  newNode->job = ++job;
	newNode->next = NULL;
	if(!*front)
	{
		*front = newNode;
		*rear = newNode;
		return;
	}
  if((*front)->p < newNode->p)
  {
      newNode->next = *front;
      (*front) = newNode;
      return;
  }
  while(temp->next && (temp->next->p > newNode->p))
  {
	     temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void dequeue(Node **front)
{
	if(*front)
	{
		Node *temp = *front;
    printf("\nJob %d(%d)", (*front)->job, (*front)->p);
		if((*front)->next)
			(*front) = (*front)->next;
    else
      (*front) = NULL;
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
      dequeue(front);
	}
  job = 0;
}

void main()
{
	Node *temp, *front = NULL, *rear = NULL;
	int val, ch, loop = 1;
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
				printf("\nDequeue : ");
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
