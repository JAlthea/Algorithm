#import <ios>
int n, k, t, a = 1, b = 1, c = 1;
int main()
{
    scanf("%d%d", &n, &k);
    t = n - k;
    while(n--)
        a *= n + 1;
    while(k--)
        b *= k + 1;
    while(t--)
        c *= t + 1;
    printf("%d", a / b / c);
}
