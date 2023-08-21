//Reversing a Sentence

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node Node;

struct Node
{
	char str[20];
	Node *next;
};

void push(Node **head, char str[])
{
	Node *newNode = malloc(sizeof(Node));
	strcpy(newNode->str, str);
	newNode->next = *head;
	*head = newNode;
}

void display(Node **head)
{
	Node *temp;
	printf("Reversed : ");
	while(*head != NULL)
	{
		printf("%s ", (*head)->str);
		temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
}

void main()
{
	int i, j = 0;
	Node *head = NULL;
	char str[200], part[20], empty[20] = " ";
	printf("Enter A String : ");
	scanf("%[^\n]%*c", str);
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ' ' || str[i] == '\0')
		{
			push(&head, part);
			j = 0;
			strcpy(part, empty);
		}
		else
		{
			part[j++] = str[i];
			part[j] = '\0';
		}
	}
	push(&head, part);
	display(&head);
}
