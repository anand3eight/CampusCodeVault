//Finding a Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int num, flag;
    struct Node *next;

};

struct Node *push(struct Node *ptr)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &new->num);
    new->flag = 0;
    new->next = ptr->next;
    ptr->next = new;
    return new;
}

int loopcheck(struct Node *ptr)
{
    while(ptr != NULL)
    {
        if(ptr->flag == 1)
            return 1;
        ptr->flag = 1;
        ptr = ptr->next;
    }
    return 0;
}

void main()
{
    int i, n;
    struct Node *current, *head = (struct Node*)malloc(sizeof(struct Node));
    head->num = 1;
    head->flag = 0;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    head->next = NULL;
    current = head;
    for(i = 0; i < n; i++)
    {
        current = push(current);
    }
    current->next = head;
    if(loopcheck(head) == 1)
        printf("Loop");
    else
        printf("Not a Loop");
}
