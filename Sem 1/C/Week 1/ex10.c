/* 10. Write a C program that asks the user to enter
two integer numbers as a length and width of a rectangle.
Then prints the area and perimeter of a rectangle */

#include<stdio.h>

void main()   {
  int length, breadth, area, perimeter ;
  printf("Enter length and Breadth for a Rectangle : ");
  scanf("%d%d", &length,&breadth );
  area = length * breadth;
  perimeter = 2 * (length + breadth);
  printf("\nArea = %d\nPerimeter = %d", area,perimeter);

}
