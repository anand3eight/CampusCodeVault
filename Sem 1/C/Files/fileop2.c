/* File Operations - fread(), fwrite() */

#include<stdio.h>

struct student
{
    int roll;
    char name[20];
}sr, sw = {1, "Anand"};

void fileread()
{
    FILE *fr;
    fr = fopen("sample.txt", "rb");
    fread(&sr, sizeof(struct student), 1, fr);
    printf("Roll : %d\nName : %s", sr.roll, sr.name);
    fclose(fr);
}

void filewrite()
{
    FILE *fw;
    fw = fopen("sample.txt", "wb");
    fwrite(&sw, sizeof(struct student), 1, fw);
    fclose(fw);
}

void main()
{
    filewrite();
    fileread();
}
