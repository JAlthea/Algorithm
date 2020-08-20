#import <ios>
int n, k, d[1001][1002];
int main()
{
    scanf("%d%d", &n, &k);
    d[0][0] = 1;
    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            if(j == 0 || j == i)
                d[i][j] = 1;
            else
                d[i][j] += d[i - 1][j] + d[i - 1][j - 1];
            if (d[i][j] > 10006)
                d[i][j] %= 10007;
        }
    }
    printf("%d", d[n][k]);
}
