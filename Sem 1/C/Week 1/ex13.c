/* 13. Write a program in C that takes minutes as input, and displays
 the total number of hours and minutes. */

 #include<stdio.h>

void main()  {
  int min ;
  float hours;
  printf("Enter Time in Minutes : ", min);
  scanf("%d", &min);
  hours = min/60.0;
  printf("\n Time in hours : %.2f", hours);
}
