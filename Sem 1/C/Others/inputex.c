/* Exercise - Non-Formatted and Formatted IP/OP Functions */

#include<stdio.h>

void main()   {
    char name[25], address[50];
    int age = 18; //Assign Default Value
    printf("Enter Your Name : ");
    gets(name);
    printf("Enter Your Present Address : ");
    gets(address);
    printf("Name    : %s\n",name );
    printf("Age     : %d\n",age);
    printf("Address : %s",address);
}
