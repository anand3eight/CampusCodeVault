//Reverse Alternate k Elements in a Linked List

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int num;
    struct Node *next;
};

int len(struct Node *ptr)
{
    int count = 0;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
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

struct Node* reverseAlternate(int val, struct Node *present, bool check)
{
    if(present == NULL)
        return NULL;
    int k = 0;
    struct Node *before = NULL, *after = NULL, *current = present;
    while((k < val) && (current!= NULL))
    {
        after = current->next;
        if(check == 1)
            current->next = before;
        before = current;
        current = after;
        k++;
    }
    if(check == 1)
    {
        present->next = reverseAlternate(k, current, !check);
        return before;
    }
    else
    {
        before->next = reverseAlternate(k, current, !check);
        return present;
    }

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

void main()
{
    int  i, k, n;
    struct Node *current, *head = (struct Node*)malloc(sizeof(struct Node));
    head->num = 0;
    head->next = NULL;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    current = head;
    for(i = 0; i < n; i++)
    {
        current = push(current);
    }
    printf("Enter Value for K : ");
    scanf("%d", &k);
    printf("\nBefore Swap : ");
    display(head->next);
    head->next = reverseAlternate(k, head->next, 1);
    printf("\nAfter Swap : ");
    display(head->next);
}
