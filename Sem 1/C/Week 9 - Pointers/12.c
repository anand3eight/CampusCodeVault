/* Vowel Remover */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void vowelRemover(char *p, int size)
{
    int index, j;
    char temp;
    for(index = 0; index < size; index++)
    {
        switch(*(p+index))
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            for(j = index; j < size-1; j++)
            {
                *(p + j) = *(p + j + 1);
            }
            *(p + j) = '\0';
    }
}

void main()
{
    char str[30], *p;
    printf("Enter a String : ");
    scanf("%s", str);
    p = str;
    vowelRemover(p, strlen(str));
    printf("%s", str);

}
