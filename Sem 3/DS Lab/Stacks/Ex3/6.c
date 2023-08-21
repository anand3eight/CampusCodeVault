//Height of 3 Cylinders

#include<stdio.h>
#include<stdlib.h>

int eq(int *s1, int *s2, int *s3, int *t1, int *t2, int *t3, int *sum)
{
    if(sum[0] == sum[1] && sum[1] == sum[2])
        return sum[0];
    else if(sum[0] > sum[1] && sum[0] > sum[2])
    {
        sum[0] -= s1[(*t1)--];
        return eq(s1, s2, s3, t1, t2, t3, sum);
    }
    else if(sum[1] > sum[2])
    {
        sum[1] -= s2[(*t2)--];
        return eq(s1, s2, s3, t1, t2, t3, sum);
    }
    sum[2] -= s3[(*t3)--];
    return eq(s1, s2, s3, t1, t2, t3, sum);

}

void main()
{
    int i, l1, l2, l3, *sum, *s1, *s2, *s3, t1, t2, t3;
    printf("Enter Length of 3 stacks : ");
    scanf("%d %d %d", &l1, &l2, &l3);
    t1 = l1, t2 = l2, t3 = l3;
    s1  = (int*)malloc(sizeof(int) * l1);
    s2  = (int*)malloc(sizeof(int) * l2);
    s3  = (int*)malloc(sizeof(int) * l3);
    sum = (int*)calloc(sizeof(int) , 3);
    printf("Enter Values for Stack 1 : ");
    for(i = 0; i < l1; i++)
    {
          scanf("%d", &s1[--t1]);
          sum[0] += s1[t1];
    }
    printf("Enter Values for Stack 2 : ");
    for(i = 0; i < l2; i++)
    {
          scanf("%d", &s2[--t2]);
          sum[1] += s2[t2];
    }
    printf("Enter Values for Stack 3 : ");
    for(i = 0; i < l3; i++)
    {
          scanf("%d", &s3[--t3]);
          sum[2] += s3[t3];
    }
    t1 = l1-1, t2 = l2-1, t3 = l3-1;
    printf("Equal Sum = %d", eq(s1, s2, s3, &t1, &t2, &t3, sum));
}
