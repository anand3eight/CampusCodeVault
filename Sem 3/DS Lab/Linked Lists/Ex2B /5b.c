//Singly Circular and Doubly Circular Linked Lists

#include<stdio.h>
#include<stdlib.h>

typedef struct DNode DNode;
struct DNode
{
    int num;
    DNode *next, *prev;
};

void insertDNode(DNode **head, int val, int pos)
{
    DNode *newNode = malloc(sizeof(DNode)), *ptr = *head, *temp = *head;
    newNode->num = val;
    if(!newNode)
    {
        printf("Memory Error");
        return;
    }
    if(pos == 1)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else
    {
        int k = 1;
        do
        {
            if(++k < pos)
              ptr = ptr->next;
            k++;
        }while(k < pos && ptr->next != *head);
        if(k != pos)
        {
          printf("Position does not Exist, Inserting at Last\n");
          newNode->next = ptr->next;
          ptr->next = newNode;
          ptr->next->prev = newNode;
          newNode->prev = ptr;
          return;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr->next->prev = newNode;
        newNode->prev = ptr;
    }
    while(ptr->next != temp)
    {
        ptr = ptr->next;
    }
    ptr->next = *head;
    (*head)->prev = ptr;
}

void deleteDNode(DNode **head, int pos)
{
    DNode *temp1, *ptr = *head, *temp = *head;
    if(pos == 1)
    {
        temp1 = *head;
        *head = (*head)->next;
    }
    else
    {
        int k = 1;
        do
        {
            if(++k < pos + 1)
              ptr = ptr->next;
        }while(k < pos + 1 && ptr != *head);
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        temp1 = ptr;
        ptr = ptr->next;
    }
    while(ptr->next != temp)
    {
        ptr = ptr->next;
    }
    ptr->next = *head;
    (*head)->prev = ptr;
    if(temp1)
        free(temp1);
}

void search(DNode **head, int pos)
{
    DNode *ptr = *head;
    if((*head)->next != *head)
        ptr = *head;
    else
        return;
    int k = 0;
    do {
        if(++k < pos)
          ptr = ptr->next;
    }while(k < pos && ptr != *head);
    printf("Value : %d", ptr->num);
}

void display(DNode **head)
{
    DNode *ptr;
    if((*head)->next != *head)
        ptr = *head;
    else
        return;
    printf("List : ");
    do
    {
        printf("%d ", ptr->num);
        ptr = ptr->next;
    }while(ptr != *head);
}

void main()
{
    DNode *head = malloc(sizeof(DNode)), *Node = malloc(sizeof(DNode));
    head = Node;
    Node->num = 0;
    Node->next = head;
    int val, pos, ch, ch1, loop = 1;
    while(loop != 0)
    {
        printf("1 : Insert \n2 : Delete \n3 : Search \n4 : Display \nEnter your Choice \n-> ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 :
                printf("1 : Insert One Element \n2 : Push Many Elements \n-> ");
                scanf("%d", &ch1);
                switch(ch1)
                {
                    case 1 :
                        printf("Enter Value : ");
                        scanf("%d", &val);
                        printf("Enter Position : ");
                        scanf("%d", &pos);
                        insertDNode(&head, val, pos);
                        break;
                    case 2 :
                        int i, n;
                        printf("Enter number of Elements : ");
                        scanf("%d", &n);
                        printf("Starting Position : ");
                        scanf("%d", &pos);
                        for(i = 0; i < n; i++)
                        {
                            printf("Enter Value : ");
                            scanf("%d", &val);
                            insertDNode(&head, val, pos++);
                        }
                        break;
                    default :
                        printf("Invalid Choice");
                  }
              break;

              case 2 :
                    printf("Enter Position : ");
                    scanf("%d", &pos);
                    deleteDNode(&head, pos);
                    break;
              case 3 :
                    printf("Enter Position : ");
                    scanf("%d", &pos);
                    search(&head, pos);
                    break;
              case 4 :
                    display(&head);
                    break;
              default :
                    printf("Invalid Choice");
          }
          printf("\nTo End, Press 0 -> ");
          scanf("%d", &loop);
        }
}
