#include <ios>

int main()
{
    int n, t, s = 1;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        s += t - 1;
    }
    printf("%d", s);
}
