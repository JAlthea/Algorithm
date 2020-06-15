#import <ios>
int h, w, n, k;
int main()
{
    scanf("%d", &k);
    while (k--)
    {
        scanf("%d%d%d", &h, &w, &n);
        printf("%d ", n % h ? n % h * 100 + n / h + 1 : h * 100 + n / h);
    }
}
