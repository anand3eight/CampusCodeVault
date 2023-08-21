//Doubly Linked List Operations

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node
{
    int num;
    Node *next, *prev;
};

Node* traverse(int pos, Node *ptr)
{
    int k = 0;
    while((k < pos-1) && (ptr != NULL))
    {
          ptr = ptr->next;
          k++;
    }
    return ptr;
}

void insertHead(Node **head)
{
	Node *newhead = (Node*)malloc(sizeof(Node));
	printf("Enter Element : ");
	scanf("%d", &newhead->num);
  newhead->next = *head;
  (*head)->prev = newhead;
  *head = newhead;
}

void insert(struct Node *ptr)
{
    Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter Value : ");
    scanf("%d", &new->num);
    new->next = ptr->next;
    ptr->next = new;
    if(ptr->next)
        ptr->next->prev = new;
    new->prev = ptr;
}

Node* push(Node *ptr)
{
    Node *new = malloc(sizeof(Node));
    printf("Enter Value : ");
    scanf("%d", &new->num);
    new->next = ptr->next;
    ptr->next = new;
    new->prev = ptr;
}

void deleteHead(Node **head)
{
  Node *temp = (*head);
	(*head) = (*head)->next;
	free(temp);
}

void delete(Node *ptr)
{
      ptr->prev->next = ptr->next;
      free(ptr);
}

Node *last(Node *lastNode)
{
    while(lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    return lastNode;
}
void search(Node *ptr)
{
	printf("Value is %d", (ptr->next)->num);
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

int position()
{
    int pos;
    printf("\nEnter Position : ");
    scanf("%d", &pos);
    return pos;
}

void main()
{
    Node *current, *head = malloc(sizeof(Node));
    head->num = 0;
    head->next = NULL;
    head->prev = NULL;
    int ch = 0, ch1 = 0, loop = 1, i = 0, n;
    while(loop != 0)
    {
      printf("\n1 : Insert \n2 : Delete \n3 : Search \n4 : Display \n-> ");
      scanf("%d", &ch);
      if(ch == 1)
      {
          printf("\n1 : Insert Head \n2 : Insert at a Position \n3 : Push Many Elements \n-> ");
      	  scanf("%d", &ch1);
      	  if(ch1 == 1)
      	        insertHead(&head);
          else if(ch1 == 2)
                insert(traverse(position(), head));
          else if(ch1 == 3)
          {
      	  	printf("Enter Number of Elements : ");
      	  	scanf("%d", &n);
            current = head;
            current = last(current);
      	  	for(i = 0; i < n; i++)
      	  	{
          		  current = push(current);
          	}
       }
      }

      else if(ch == 2)
      {
      	  printf("To delete Head, Press 1 -> ");
      	  scanf("%d", &ch1);
      	  if(ch1 == 1)
				        deleteHead(&head);
          else
		   		      delete(traverse(position()+1, head));
      }
	    else if(ch == 3)
	  	     search(traverse(position(), head));
      else if(ch == 4)
          display(head->next);
      else
          printf("\nInvalid Choice");
      printf("\nTo End : Press 0 -> ");
      scanf("%d", &loop);
    }

}
