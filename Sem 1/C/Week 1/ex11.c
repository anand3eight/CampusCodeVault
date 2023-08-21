/* 11. Write a C program that calculates the volume of a sphere. */

#include<stdio.h>

void main()   {
  int radius ;
  float volume;
  printf("Enter the Radius for a Sphere : ", radius );
  scanf("%d", &radius);
  volume = (4 * 3.14 * radius * radius * radius )/3;
  printf("\nVolume = %f", volume);
}
