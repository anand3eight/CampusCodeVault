/* Complex Number */

#include<stdio.h>

struct Complex
{
    float real, imag;
}a, b, c;

void main()
{
    int div;
    printf("Enter Real and Imaginary Values for a : ");
    scanf("%f%*c%f", &a.real, &a.imag);
    printf("Enter Real and Imaginary Values for b : ");
    scanf("%f%*c%f", &b.real, &b.imag);
    char op;
    printf("Enter Operator : ");
    scanf("\n%c", &op);
    switch(op)
    {
        case '+' :
            c.real = a.real + b.real;
            c.imag = a.imag + b.imag;
            break;
        case '-' :
            c.real = a.real - b.real;
            c.imag = a.imag - b.imag;
            break;
        case 'x' :
        case '*' :
            c.real = (a.real * b.real) - (a.imag * b.imag);
            c.imag = (a.imag * b.real) + (a.real * b.imag);
            break;
        case '/' :
            div = (b.real * b.real) + (b.imag * b.imag);
            c.real = ((a.real * b.real) + (a.imag * b.imag))/div;
            c.imag = ((a.imag * b.real) - (a.real * b.imag))/div;
            break;
    }
printf("%.2f + %.2fi", c.real, c.imag);
}
