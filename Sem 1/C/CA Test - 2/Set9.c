/* Excel Column Numbers to Names */
#include<stdio.h>

void main()
{
	int col, i, rem;
	char colName[30];
	printf("Enter : ");
	scanf("%d", &col);
	for(i = 0, rem = 0; col > 0; col /= 26)
	{
	    rem = col % 26;
	    if(rem == 0)
	    {
	    	colName[i] = (char)64 + 26 + rem;
	    	col--;
	    	i++;
	    	continue;
	    }
	     colName[i] = (char)64 + rem;
	     i++;
	}
	for(i -= 1; i >= 0; i--)
	{
		printf("%c", colName[i]);
	}
}
