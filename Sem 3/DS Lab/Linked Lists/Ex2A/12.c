//Deleting Alternate Elements

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

void delete(struct Node *ptr)
{
      struct Node *temp = ptr->next;
      ptr->next = (ptr->next)->next;
      free(temp);
}

void deleteAlternate(struct Node *ptr)
{
    while(ptr->next != NULL)
    {
        delete(ptr);
        if(ptr->next != NULL)
            ptr = ptr->next;
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
    head->next = NULL;
    current = head;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        current = push(current);
    }
    printf("\nBefore Deletion : ");
    display(head->next);
    deleteAlternate(head->next);
    printf("\nAfter Deletion : ");
    display(head->next);
}
