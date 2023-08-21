/* 2. Write a program to get the Name of the person and age.
 The program should display the obtained
details from the user in the following format:
Name of the Person: Aravind
Age: 22
The program should also print an additional message
 “Senior citizens are eligible for waiver.
Contact bookings” if the individual is a senior citizen */

#include<stdio.h>

void main()  {
    int age ;
    char name[80];
    printf("Enter Your Name and Age : ");
    gets(name);
    scanf("%d", &age);
    printf("\nName of the Person : %s\nAge : %d\n", name,age);
    if(age > 60) {
      printf("Senior citizens are eligible for waiver.\nContact bookings");
    }
}
