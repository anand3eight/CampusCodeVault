/* Vehicle Info */

#include<stdio.h>

struct Vehicle
{
    char modelName[10], type[10], fuel[8];
    int modelNum;
} v[10];

void insert(int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("Enter Details of Vehicle %d :\n", i+1);
        printf("(Vehicle Name, Type, Fuel, Model Number )\n");
        scanf("%s %s %s \n %d", v[i].modelName, v[i].type, v[i].fuel, &v[i].modelNum);
    }
    printf("Items Entered Into Database\n");
}

void display(int i)
{
    printf("%10s %10s %10s %4d", v[i].modelName, v[i].type, v[i].fuel, v[i].modelNum);
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
              printf("Enter Number of Vehicles : ");
              scanf("%d", &size);
              insert(size);
              break;
        case 2 :
              printf("Enter Vehicle ID : ");
              scanf("%d", &id);
              display(id-1);
              break;
        default :
              printf("Enter Valid Choice : ");
    }
    printf("\nDo You Want to Continue : (1 - Yes) : ");
    scanf("%d", &check);
    if(check != 1)   break;
  }
}
