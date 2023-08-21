/* 1. Given the three subject marks for a student,
print the subject in which the student has secured the
maximum marks. */

 #include<stdio.h>

 void main()
 {
    int math, physics, chemistry ;
    printf("Enter Your Math, Physics and Chemistry Marks : ");
    scanf("%d%d%d", &math, &physics, &chemistry);
    if(math > physics  &&  math > chemistry )
    {
        printf("MATH");
    }
    else if(physics > chemistry)
    {
        printf("PHYSICS");
    }
    else
    {
        printf("CHEMISTRY");
    }
    printf("\nEND !");
 }
