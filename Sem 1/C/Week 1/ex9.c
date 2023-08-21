/* 9. Write a C program that reads in the radius of a circle and
prints the circle’s diameter,
circumference, and area. Use the constant value 3.14 for π. */

#include<stdio.h>

void main()   {
  int radius, dia ;
  float area , circumference ;
  printf("Enter the Radius : " );
  scanf("%d", &radius);
  dia = radius*2;
  circumference = 3.14 * dia ;
  area = 3.14 * radius * radius;
  printf("\nDiameter = %d", dia );
  printf("\nCircumference = %f", circumference);
  printf("\nArea = %f", area);
}
