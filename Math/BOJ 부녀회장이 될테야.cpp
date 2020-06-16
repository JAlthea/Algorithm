#import <ios>
int i, k, n, d[15][15];
int main()
{
    for (; i<15; i++) 
        d[0][i] = i;
    for (i=1; i<15; i++)
        for (k=1; k<15; k++)
            for(n=1; n<=k; n++)
                d[i][k] += d[i-1][n];
    scanf("%d", &i);
    while (i--)
    {
        scanf("%d%d", &k, &n);
        printf("%d ", d[k][n]);
    }
}
