#import <ios>
int a = 1e9, b, c, i = 5;
int main()
{
    b = a;
    while (i--)
    {
        scanf("%d", &c);
        if (i > 1 && a > c) a = c;
        if (i < 2 && b > c) b = c;
    }
    printf("%d", a + b - 50);
}
