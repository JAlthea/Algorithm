#include <ios>
int main()
{
    int c, k, p, count = 0;
    scanf("%d%d%d", &c, &k, &p);
    for (int i=1; i<=c; i++)
        count += k * i + p * i * i;
    printf("%d", count);
}
