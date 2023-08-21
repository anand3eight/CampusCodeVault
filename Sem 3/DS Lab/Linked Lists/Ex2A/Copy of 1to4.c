//Linked List Operations

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};

struct Node* traverse(int pos, struct Node *ptr)
{
   int k = 0;
    while((k < pos-1) && (ptr != NULL))
    {
          ptr = ptr->next;
          k++;
    }
    return ptr;

}

struct Node* insertHead(struct Node *head)
{
	struct Node *newhead = (struct Node*)malloc(sizeof(struct Node));
	struct Node *temp = head;
	newhead->next = temp;
	printf("Enter Element : ");
	scanf("%d", &newhead->num);
	head = newhead;
	return head;
}

void insert(struct Node *ptr)
{

    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &new->num);
    new->next = ptr->next;
    ptr->next = new;
}

struct Node *push(struct Node *ptr)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &new->num);
    new->next = ptr->next;
    ptr->next = new;
    return new;
}

struct Node* deleteHead(struct Node *head)
{
	struct Node *temp = head;
	head = head->next;
	free(temp);
	return head;
}

void delete(struct Node *ptr)
{
      struct Node *temp = ptr->next;
      ptr->next = (ptr->next)->next;
      free(temp);
}

void search(struct Node *ptr)
{
	printf("Value is %d", (ptr->next)->num);
}
void display(struct Node *ptr)
{
      printf("\nList : ");
      while(ptr != NULL)
      {
            printf("%d ", ptr->num);
            ptr = ptr->next;
      }
}

struct Node *lastNode(struct Node *ptr)
{
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr;
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
    struct Node *current, *head = (struct Node*)malloc(sizeof(struct Node));
    head->num = 0;
    head->next = NULL;
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
      	        head = insertHead(head);
          else if(ch1 == 2)
                insert(traverse(position(), head));
          else if(ch1 == 3)
          {
      	  	printf("Enter Number of Elements : ");
      	  	scanf("%d", &n);
            current = lastNode(head);
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
				        head = deleteHead(head);
          else
		   		      delete(traverse(position(), head));
      }
	    else if(ch == 3)
	  	     search(traverse(position(), head));
      else if(ch == 4)
          display(head);
      else
          printf("\nInvalid Choice");
      printf("\nTo End : Press 0 -> ");
      scanf("%d", &loop);
    }

}
