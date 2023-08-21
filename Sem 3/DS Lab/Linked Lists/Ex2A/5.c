//Reverse a Linked List

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

struct Node* reverse(struct Node *current)
{
    struct Node *before = NULL, *after = NULL;
    while(current != NULL)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
    }
    return before;
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
    int  i, n;
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
    display(head->next);
    head = reverse(head->next);
    display(head);
}
