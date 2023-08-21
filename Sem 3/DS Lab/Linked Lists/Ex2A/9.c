//Swap Alternate Elements

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

void alternateSwap(struct Node *ptr)
{
    int temp;
    while(ptr != NULL && ptr->next!=NULL)
    {
        temp = ptr->num;
        ptr->num = (ptr->next)->num;
        (ptr->next)->num = temp;
        ptr = (ptr->next)->next;
    }
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

void main()
{
    int i, n;
    struct Node *current, *head = (struct Node*)malloc(sizeof(struct Node));
    head->num = 1;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    head->next = NULL;
    current = head;
    for(i = 0; i < n; i++)
    {
        current = push(current);
    }
    printf("\nBefore Swap : ");
    display(head->next);
    alternateSwap(head->next);
    printf("\nAfter Swap : ");
    display(head->next);
}
