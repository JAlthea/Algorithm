#import <ios>
int a, b, i, j, s, t, d[10001] = {0, 1};
int main()
{
    for (i=2; i*i<=10000; i++)
        if (!d[i])
            for (j=i*i; j<10001; j+=i)
                d[j]++;
    scanf("%d%d", &a, &b);
    for (t=b; a<=b; a++)
    {
        if (!d[a])
        {
            a < t ? t=a : t;
            s += a;
        }
    }
    s ? printf("%d\n%d", s, t) : puts("-1");
}
