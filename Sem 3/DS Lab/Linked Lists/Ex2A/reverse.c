#include<stdio.h>
#include<stdlib.h>
struct lnode
{
int data;
struct lnode *next;
};
typedef struct lnode node;
node*head=NULL;
node*prev;
void insertatbegin(int val)
{
  node *newnode=(node*)malloc(sizeof(node));
   if(newnode==NULL)
    {
    printf("memory isnt allocated");
    return;
    }
    newnode->data=val;
   if(head==NULL)
   {
    newnode->next=NULL;
    head=newnode;
   }
   else
   {
    newnode->next=head;
     head= newnode;
   }
}
void display()
 {
   if(head==NULL)
    {
       printf("The list is empty");
    }
    node *temp=head;
   while(temp!=NULL)
    {
    printf("%d ",temp->data);
    temp=temp->next;
    }
printf("\n");
}
void reversal()
{
    node *prev=NULL;
    node *current=head;
    node *next=head->next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head = prev;
}
int main()
{
    int pos,val,ch;
    while(1)
    {
        printf("\n1.to add at begining");
        printf("\n2.to display");
        printf("\n3.to reverse");
        printf("\nenter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the value ");
                scanf("%d",&val);
                insertatbegin(val);
                break;
            case 2:
                display();
                break;
            case 3:
                reversal();
                break;
            case 4:
                exit(0);
        }
    }
}


