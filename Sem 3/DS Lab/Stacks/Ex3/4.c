//Infix to Postfix conversion and Evaluation

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int pr(char ch)
{
    switch(ch)
    {
        case '(' :
            return 0;
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
            return 2;
        case '^' :
            return 3;
    }
}

int cal(char ch, int n1, int n2)
{
    switch(ch)
    {
        case '+' :
            return n1 + n2;
        case '-' :
            return n1 - n2;
        case '*' :
            return n1 * n2;
        case '/' :
            return n1 / n2;
        case '^' :
            return (int)pow((double)n1, (double)n2);
    }
}

void main()
{
	int *stack, i, len, p, c, op1, op2, index = 0, top = -1;
  char ch, op, exp[100], *postfix, *opstack;
  printf("Enter infix Expression : ");
	scanf("%s", exp);
  for(len = 0; exp[len] != '\0'; len++);
  postfix = (char *)malloc(sizeof(char) * len);
  opstack = (char *)malloc(sizeof(char) * len);
  stack   = (int *)malloc(sizeof(int) * len);
  for(i = 0; exp[i] != '\0'; i++)
  {
      if(isdigit(exp[i]) != 0)
          postfix[index++] = exp[i];
      else
          if(exp[i] == '(')
              opstack[++top] = exp[i];
          else if(exp[i] == ')')
          {
              op = opstack[top--];
              while(op != '(' && top != -1)
              {
                  postfix[index++] = op;
                  op = opstack[top--];
              }
          }
          else
          {
              if(top != -1)
                p = pr(opstack[top]);
              else
                p = 0;
              c = pr(exp[i]);
              if(c < p)
                  postfix[index++] = opstack[top--];
              opstack[++top] = exp[i];
          }

    }
    while(top != -1)
    {
        postfix[index++] = opstack[top--];
    }
    postfix[index] = '\0';
    printf("Postfix Expression : %s", postfix);
    stack = (int *)malloc(sizeof(int) * len);
    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isdigit(postfix[i]) != 0)
        {
            ch = postfix[i];
            stack[++top] = atoi(&ch);
        }
        else
        {
            op1 = stack[top--];
            op2 = stack[top--];
            stack[++top] = cal(postfix[i], op2, op1);
        }
    }
    printf("\nAnswer : %d", stack[top]);
}
