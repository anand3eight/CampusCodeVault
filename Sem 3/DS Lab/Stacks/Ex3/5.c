//Balancing Parenthesis

#include<stdio.h>
#include<stdlib.h>
char *stack;

void push(char c, int *pos, int len)
{
	if(*pos == len-1)
	{
		printf("\nOverflow");
		return;
	}
  stack[++(*pos)] = c;

}

char pop(int *pos)
{
	if(*pos == -1)
	{
		printf("\nUnderflow");
		return 0;
	}
	return stack[(*pos)--];
}

void main()
{
  char str[30];
	int i, len, check = 1, pos = -1;
  printf("Enter String : ");
  scanf("%s", str);
  for(len = 0; str[len] != '\0'; len++);
  stack = (char *)malloc(sizeof(char));
  for(i = 0; i < len; i++)
  {
      if(check == 0)
          break;
      if(str[i] == '{' || str[i] == '[' || str[i] =='(')
        push(str[i], &pos, len);
      else
        switch(str[i])
        {
            case '}' :
                if (pop(&pos) == '{')
                    continue;
                check = 0;
            case ']' :
                if (pop(&pos) == '[')
                    continue;
                check = 0;
            case ')' :
                if (pop(&pos) == '(')
                    continue;
                check = 0;

        }
				if(check == 0)
						break;
  }
  if(check == 0 || pos != -1)
      printf("Not Balanced");
  else
      printf("Balanced");

}
