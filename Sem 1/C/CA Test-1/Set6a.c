/* Square Plot Problem */

#include<stdio.h>

void main()
{
    int len, bdt, x, i;
    printf("Enter Length and Breadth of Rectangular Plot : ");
    scanf("%d%d", &len, &bdt);
    int min = len < bdt ? len : bdt;
    x = 1;
    int check = 0;
    int ans = x;
    for(i = min; i >= 1; i--)
    {
        for(x = 1; x <= min; x++)
        {
            if(x*(i*i) == (len*bdt))
            {
            printf("%d", x);
            check = 1;
            }
        }
        if(check == 1)  break;
    }
}
