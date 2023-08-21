/* Printing Octal and Hexadecimal Numbers */

#include<stdio.h>

void main()   {
      int oct = 305;
      int hex = 305;
      printf("Decimal Value : %d and %d\n", oct,hex);
      printf("Normal Values in base8 and base16 : %o and %x", oct,hex);
      printf("\nWith Prefix : %#o and %#x ", oct,hex);
}
