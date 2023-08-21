/* Hardware Item Database */

#include<stdio.h>
#include<string.h>

struct hwitem
{
    char title[30], origMan[30], type[2];
    int price;
    float month1, month2, month3;
} h[15];

void insert(int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("Enter Details of Item %d :\n", i+1);
        printf("(Item Name, Item Price, Previous 3 Month Sales, Item Type, Original Manufacturer)\n");
        scanf("%s %d %f %f %f %s %s", h[i].title, &h[i].price, &h[i].month1, &h[i].month2, &h[i].month3, h[i].type, h[i].origMan);
    }
    printf("Items Entered Into Database\n");
}

void display(int i)
{
    printf("%15s %5d %5.2f %5.2f %5.2f %15s %2s\n", h[i].title, h[i].price, h[i].month1, h[i].month2, h[i].month3, h[i].type, h[i].origMan);
}

void main()
{
  int i, size;
  int ch, check, id;
  while(1)
  {
    printf("1 : Enter Item\n2 : Display Item\n");
    printf("Enter Your Choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1 :
              printf("Enter Number of Items : ");
              scanf("%d", &size);
              insert(size);
              break;
        case 2 :
              printf("Enter Item ID : ");
              scanf("%d", &id);
              display(id-1);
              break;
        default :
              printf("Enter Valid Choice : ");
    }
    printf("Do You Want to Continue :(1 - Yes)");
    scanf("%d", &check);
    if(check != 1)   break;
  }
}
