//Array Length - Even or Odd
//Including head Node

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};

struct Node *push(struct Node *ptr)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &new->num);
    new->next = ptr->next;
    ptr->next = new;
    return new;
}

int len(struct Node *ptr)
{
	int count = 0;
    while(ptr != NULL)
    {
	    count++;
        ptr = ptr->next;
    }
    return count;
}

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

void search(struct Node *ptr)
{
	printf("\nMidValue is %d", (ptr->next)->num);
}

void main()
{
 	  int i, n;
	  struct Node *current, *head = (struct Node*)malloc(sizeof(struct Node));
    head->num = 1;
    head->next = NULL;
    current = head;
	  printf("Enter Number of Elements : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        current = push(current);
    }
    int l = len(head->next);
    if(l % 2 == 0)
    	printf("Even");
    else
    {
    	printf("Odd");
    	search(traverse(l/2 + 1, head));
	  }
}
