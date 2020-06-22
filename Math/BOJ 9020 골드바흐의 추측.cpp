#import <ios>
int d[10001], t, n, s[2], i, j;
int main()
{
    for (i=2; i*i<10001; i++)
        if (!d[i])
            for (j=i+i; j<10001; j+=i)
                d[j]++;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        if (!d[n-2])
            s[0] = 2, s[1] = n - 2;
        for (i=3; i<=n/2; i+=2)
            if (!d[i] && !d[n-i])
                s[0] = i, s[1] = n - i;
        printf("%d %d\n", s[0], s[1]);
    }
}
