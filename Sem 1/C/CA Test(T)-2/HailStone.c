/* Print the HailStone Sequence using Functions */

void hailStone(int n, int k)
{
    for(int i = 0; i < k; i++)
    {
        if(n % 2  ==  0)
        {
            printf("%d ", n);
            n /= 2;
        }
        else
        {
            printf("%d ", n);
            n = (3*n) + 1;
        }
    }
}
void main()
{
    printf("Enter N and K Values : ");
    int n, k;
    scanf("%d%*c%d", &n, &k);
    hailStone(n,k);
}
