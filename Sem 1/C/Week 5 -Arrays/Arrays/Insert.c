/* To Insert an element in an array */

#include<stdio.h>

void main()
{
    int i, a[6] = {1,2,3,4,5};
    int elmt, pos, temp;
    printf("Enter : ");
    scanf("%d%d", &elmt, &pos);
    for(i = pos-1; i < 6; i++ )
    {
        temp = a[i];
        a[i] = elmt;
        elmt = temp;
    }
    printf("ARRAY ");
    for(i = 0; i < 6; i++)
        printf("%d ", a[i]);

}
