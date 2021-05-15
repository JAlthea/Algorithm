#import <ios>
int n, i, a, b;
int main()
{
    for (scanf("%d", &n); i<n; i++)
    {
        a = b = i;
        while (b)
            a += b % 10, b /= 10;
        if (a == n)
        {
            printf("%d", i);
            return 0;
        }
    }
    puts("0");
}
