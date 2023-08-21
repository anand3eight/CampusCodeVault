//Number of Occurences of an Element

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

int count(int val, struct Node *ptr)
{
	int count = 0;
    while(ptr != NULL)
    {
    	  if(ptr->num == val)
    	  		count++;
          ptr = ptr->next;
    }
    return count;

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
    int val;
    printf("Enter Value to be Counted : ");
    scanf("%d", &val);
    printf("Count of %d is %d", val, count(val, head));
}
