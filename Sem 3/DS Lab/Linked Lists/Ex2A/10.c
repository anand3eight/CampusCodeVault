//Sum of Last N nodes

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
        ptr = ptr->next;
        count++;
    }
    return count;
}
int lastNsum(struct Node *ptr)
{
    int sum = 0;
    while(ptr != NULL)
    {
        sum += ptr->num;
        ptr = ptr->next;
    }
    return sum;
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
    printf("Enter N value : ");
    scanf("%d", &n);
    printf("Sum of Last %d nodes is %d", n, lastNsum(traverse(len(head)-n, head->next)));
}
