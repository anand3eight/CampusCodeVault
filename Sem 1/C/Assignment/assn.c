#include<stdio.h>
#include<stdlib.h>
void digitCount(int num, int *p)
{
    switch(num)
    {
        case 0:
            (*(p+0))++;
            break;
        case 1:
            (*(p+1))++;
            break;
        case 2:
            (*(p+2))++;
            break;
        case 3:
            (*(p+3))++;
            break;
        case 4:
            (*(p+4))++;
            break;
        case 5:
            (*(p+5))++;
            break;
        case 6:
            (*(p+6))++;
            break;
        case 7:
            (*(p+7))++;
            break;
        case 8:
            (*(p+8))++;
            break;
        case 9:
            (*(p+9))++;
            break;
    }
}
void digitFinder(int num, int *p)
{
    int i, rem;
    for(rem = 0; num > 0;)
    {
        rem = num % 10;
        digitCount(rem, p);
        num /= 10;
    }
}

void main()
{
    int n;
    printf("Enter : ");
    scanf("%d", &n);
    int i, a[10] = {0,0,0,0,0,0,0,0,0,0};
    for(i = 1; i <= n; i++)
    {
        digitFinder(i, a);
    }
    printf("{");
    for(i = 0; i < 10; i++)
    {
        printf("%d", a[i]);
        if(i < 9) printf(", ");
    }
    printf("}");
}
