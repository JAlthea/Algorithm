#import <ios>
int d[10], i, n, s, c;
int main()
{
    for(scanf("%d%d",&n, &s); i < n; ++i)
        scanf("%d", &d[i]);
    for(i = n - 1; s; --i)
        if(d[i])
            while(d[i] <= s)
                s -= d[i], c++;
    printf("%d", c);
}
