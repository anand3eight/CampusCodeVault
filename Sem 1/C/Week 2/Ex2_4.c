/* 4. Write C program which will input the age and
height of a child and decide whether he is normal,
tall or short. The criteria are:
age 2 - 3 :
"SHORT" if height < 55
"NORMAL" if 55 <= height < 75
"TALL" if height >=75
age 4- 5:
"SHORT" if height < 75
"NORMAL" if 75 <= height < 100
"TALL" if height >=100
The program should warn the user that he must
enter an age between 2 - 5. If he enters an age
outside this range, the program should
output the message "the age given is out of range".*/

#include<stdio.h>

void main()
{
  int age, height;
  printf("Enter Your Child\'s Age and Height : ");
  scanf("%d%d", &age,&height);
  if( age >= 2 && age <= 3)
  {
      if(height < 55)
      {
          printf("SHORT");
      }
      else if(height >= 55 && height < 75)
      {
          printf("NORMAL");
      }
      else if(height >= 75)
      {
          printf("TALL");
      }
  }
  else if( age >= 4 && age <= 5)
  {
      if(height < 75)
      {
          printf("SHORT");
      }
      else if(height >= 75 && height < 100)
      {
          printf("NORMAL");
      }
      else if(height >= 100)
      {
          printf("TALL");
      }
  }
  else
  {
        printf("The Given Age is Not Valid");
  }
}
