/* File Operations - fscanf() and fprintf() */

#include<stdio.h>
void fileread()
{
  FILE *fr;
  fr = fopen("sample.txt", "rb");
  char name[20];
  int num;
  fscanf(fr, "%d %[^\n]s", &num, name);
  printf("%d %s\n", num, name);
  fclose(fr);
}
void filewrite()
{
    FILE *fw;
    fw = fopen("sample.txt", "wb");
    char name[20];
    int num;
    printf("Enter(Num, Name) : ");
    scanf("%d %*c %[^\n]s", &num, name);
    fprintf(fw, "%d %s\n", num, name);
    fclose(fw);
}

void main()
{
    filewrite();
    fileread();
}
