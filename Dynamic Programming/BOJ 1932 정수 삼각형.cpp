#import<ios>

int n,d[500][500];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            scanf("%d", &d[i][j]);
    for(int i=n-1; i>0; i--)
        for(int j=0; j<n-1; j++)
            d[i-1][j] += d[i][j] > d[i][j+1] ? d[i][j] : d[i][j+1];
    printf("%d", d[0][0]);
}
