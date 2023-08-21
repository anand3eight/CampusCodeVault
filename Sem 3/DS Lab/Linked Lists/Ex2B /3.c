//Single Linked List - Distinct Sorted Array

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int num;
	struct Node *next;
};

typedef struct Node Node;

Node *push(struct Node *ptr)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &new->num);
    new->next = ptr->next;
    ptr->next = new;
    return new;
}

void display(Node *ptr)
{
      printf("\nList : ");
      while(ptr != NULL)
      {
            printf("%d ", ptr->num);
            ptr = ptr->next;
      }
}

void distinct(Node *ptr)
{
	while(ptr->next != NULL)
	{
		if(ptr->num == ptr->next->num)
		{
			Node *temp = ptr->next;
			ptr->next = (ptr->next)->next;
			free(temp);

		}
		else
		{
			if(ptr->next != NULL)
				ptr = ptr->next;
		}
	}
}

void main()
{
	int i, n;
	Node *current, *head = (struct Node*)malloc(sizeof(struct Node));
    head->num = 0;
    head->next = NULL;
    current = head;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        current = push(current);
    }
    printf("\nBefore Operation : ");
    display(head->next);
    distinct(head->next);
    printf("\nAfter Operation : ");
    display(head->next);
}
