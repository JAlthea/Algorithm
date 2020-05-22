#import <ios>

void f(int n, int a, int b, int c)
{
    if (!n) return;
    f(n-1, a, c, b);
    printf("%d %d ", a, c);
    f(n-1, b, a, c);
}

int main(int n)
{
    scanf("%d", &n);
    printf("%d ", (1 << n) - 1);
    f(n, 1, 2, 3);
}
