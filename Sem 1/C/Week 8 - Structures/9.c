/* Master Table */

#include<stdio.h>
#include<string.h>

struct master
{
    char name[30], code[10];
    int pay, exp;
} m[15];

void insert(int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("Enter Details of Person %d :\n", i+1);
        printf("(Name, Code, Pay, Experience)\n");
        scanf("%s %s %d %d", m[i].name, m[i].code, &m[i].pay, &m[i].exp);
    }
    printf("Items Entered Into Database\n");
}

void delete(int i)
{
    strcpy(m[i].name, "PersonDeletedIGNORE");
    strcpy(m[i].code, "-");
    m[i].pay = 0;
    m[i].exp = 0;
    printf("Item %d is deleted\n", i + 1);
}

void display(int size)
{
  int i;
  for(i = 0; i < size; i++)
  {
    printf("%20s %5s %5d %5d\n", m[i].name, m[i].code, m[i].pay, m[i].exp);
  }
}


void main()
{
  int i, size;
  int ch, check, id;
  while(1)
  {
    printf("1 : Enter Person(s)\n2 : Delete Person\n3 : Display Persons");
    printf("\nEnter Your Choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1 :
              printf("Enter Number of Person : ");
              scanf("%d", &size);
              insert(size);
              break;
        case 2 :
              printf("Enter Person ID : ");
              scanf("%d", &id);
              delete(id-1);
              break;
        case 3 :
              display(size);
              break;
        default :
              printf("Enter Valid Choice : ");
    }
    printf("Do You Want to Continue :(1 - Yes) ");
    scanf("%d", &check);
    if(check != 1)   break;
  }
}
