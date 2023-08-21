#include<stdio.h>
struct Point
{
char c;
int x, y;
};

int main()
{
struct Point p1 = {'K',1,2};
p1.x=4;
struct Point *p2 = &p1;
printf("%d %d %c", p2->x, p2->y,p2->c);
return 0;
}

