//Access of Structures

#include<stdio.h>
#include<stdlib.h>

struct Student{
    int id;
    char name[30];
}s1, *s2;

void main()
{
    printf("Name : ");
    scanf("%s", s1.name);
    printf("ID : ");
    scanf("%d", &s1.id);
    s2 = &s1;
    printf("Student 1 \nNormal\nID : %d\nName : %s\n", s1.id, s1.name);
    printf("\nPointer \nID : %d\nName : %s\n", s2->id, s2->name);
}
