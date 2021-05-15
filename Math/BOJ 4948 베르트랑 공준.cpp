#import <ios>
int t, i, j, d[250000];
int main()
{
    for (; i<250000; i++)
        d[i]++;
    for (i=2; i<250000; i++)
        if (d[i])
            for (j=i+i; j<250000; j+=i)
                d[j] = 0;
    while (scanf("%d", &t))
    {
        if (!t) break;
        for (j=0, i=t+1; i<=t+t; i++)
            if (d[i])
                j++;
        printf("%d\n", j);
    }
}
