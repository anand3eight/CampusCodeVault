/* Find the SubString Index */
#include<stdio.h>
#include<string.h>
int strStr(char str[20], char substr[10])
{
    int i, j, check = -1;
    for(i = 0; i < strlen(str); i++)
    {
      if(str[i] == substr[0])
      {
        for(j = 1; j < strlen(substr); j++)
        {
            if(str[i+j] == substr[j]) check = 1;
            else
            {
              check = -1;
              break;
            }
        }
      }
      if(check == 1)  return i;
    }
    return -1;
}
void main()
{
    char str[20], substr[10];
    printf("Enter String And SubString :\n");
    scanf("%s", str);
    scanf("%s", substr);
    printf("%d", strStr(str, substr));
}
