//Singly Circular and Doubly Circular Linked Lists

#include<stdio.h>
#include<stdlib.h>

typedef struct SNode SNode;
struct SNode
{
    int num;
    SNode *next;
};

void insertSNode(SNode **head, int val, int pos)
{
    SNode *newNode = malloc(sizeof(SNode)), *ptr = *head, *temp = *head;
    newNode->num = val;
    if(!newNode)
    {
        printf("Memory Error");
        return;
    }
    if(pos == 1)
    {
        newNode->next = *head;
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
          return;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    while(ptr->next != temp)
    {
        ptr = ptr->next;
    }
    ptr->next = *head;
}

void deleteSNode(SNode **head, int pos)
{
    SNode *temp1, *ptr = *head, *temp = *head;
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
            if(++k < pos)
              ptr = ptr->next;
        }while(k < pos && ptr != *head);

        temp1 = ptr->next;
        ptr->next = ptr->next->next;
        free(temp1);
    }
    while(ptr->next != temp)
    {
        ptr = ptr->next;
    }
    ptr->next = *head;
    if(temp1)
        free(temp1);
}

void search(SNode **head, int pos)
{
    SNode *ptr = *head;
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

void display(SNode **head)
{
    SNode *ptr;
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
    SNode *head = malloc(sizeof(SNode)), *Node = malloc(sizeof(SNode));
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
                        insertSNode(&head, val, pos);
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
                            insertSNode(&head, val, pos++);
                        }
                        break;
                    default :
                        printf("Invalid Choice");
                  }
              break;

              case 2 :
                    printf("Enter Position : ");
                    scanf("%d", &pos);
                    deleteSNode(&head, pos);
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
