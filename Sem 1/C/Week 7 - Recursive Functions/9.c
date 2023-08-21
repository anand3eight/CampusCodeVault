/* Word Count */

#include<stdio.h>
#include<string.h>

int WordCount(char sentence[100], int len, int i, int count)
{
    if(len > -1)
    {
        if(sentence[i] == ' ')  count++;
        WordCount(sentence, len - 1, i + 1, count);
    }
    else  return count;
}
void main()
{
    int sentence[100];
    printf("Enter a Sentence : ");
    scanf("%[^\n]s", sentence);
    printf("Number Of Words : %d", WordCount(sentence, strlen(sentence), 0, 0));
}
