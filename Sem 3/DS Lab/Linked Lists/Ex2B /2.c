//Split - Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int num, flag;
    struct Node *next;
};

struct Node *push(struct Node *ptr)
{
    struct Node *new = malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &new->num);
    new->flag = 0;
    new->next = ptr->next;
    ptr->next = new;
    return new;
}

void display(struct Node *ptr)
{
      struct Node *temp = ptr;
      printf("\nList : ");
      do
      {
            printf("%d ", ptr->num);
            ptr = ptr->next;
      }while(ptr != temp);
}

struct Node* split(struct Node *ptr, int val)
{
	int k = 0;
	struct Node *ptr2, *head = ptr;
	while(ptr!= NULL && k < val-1)
	{
		ptr = ptr->next;
		k++;
	}
	struct Node* temp = ptr->next;
	ptr->next = head;
	ptr2 = temp;
  while(ptr2->next->next != head)
  {
      ptr2 = ptr2->next;
  }
  ptr2->next = temp;
  return temp;
}

int len(struct Node *ptr, struct Node *head)
{
	int length = 0;
    while(ptr->next != NULL)
    {
    	if(ptr == head)
    	{
    		ptr = ptr->next;
    		continue;
    	}
    	ptr->flag += 1;
    	if(ptr->flag > 1)
    		return length;
        ptr = ptr->next;
        length++;
	}
}

void main()
{
    struct Node *current, *newhead, *head = malloc(sizeof(struct Node));
    int i, n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    current = head;
    for(i = 0; i < n; i++)
    {
       current = push(current);
    }
    current->next = head;
	  int l = len(head->next, head);
	  if(l%2)
	  {
		    newhead = split(head->next, l/2 + 1);
	  }
	  else
	  {
		    newhead = split(head->next, l/2);
	  }
	  printf("\nPart 1 : ");
	  display(head->next);
	  printf("\nPart 2 : ");
	  display(newhead);
}
