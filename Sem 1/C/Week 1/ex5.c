/* 5. A C program contains the following statements
#include <stdio.h>
char text[80];
Suppose the string “Programming with C can be a
challenging creative activity” is
assigned to the text include printf statements in the
above program to display the first eight
characters of the text and display the first eight characters
 preceded by five blank spaces. */

#include<stdio.h>

void main()   {
  char text[100] = "Programming with C can be a challenging creative activity";
  printf("%13.8s", text);

}
