/* Anagram Finder */

#include<stdio.h>
#include<string.h>
int strDiff(char str1[10], char str2[10])
{
    int i, net = 0;
    for(i = 0; i < strlen(str1); i++)
    {
        net += ( (int)str1[i] - (int)str2[i] );
    }
    return net;
}
void anagram(char strArray[10][10], int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        if(strArray[i][0] != '\0')  printf("%s\n", strArray[i]);
        for(j = i+1; j < size; j++)
        {
            if(strDiff(strArray[i], strArray[j]) == 0)
            {
              if(strArray[j][0] != '\0')  printf("%s\n", strArray[j]);
              strArray[j][0] = '\0';
            }
        }
    }
}
void main()
{
    char strArray[10][10];
    int i, size;
    printf("Enter the Size : ");
    scanf("%d", &size);
    printf("Enter :\n");
    for(i = 0; i < size; i++)
    {
        scanf("%s", strArray[i]);
    }
    printf("-------\n");
    anagram(strArray, size);
}
