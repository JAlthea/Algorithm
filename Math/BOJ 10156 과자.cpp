#include <ios>
int main()
{
    int k, n, m;
    scanf("%d%d%d", &k, &n, &m);
    printf("%d", k * n > m ? k * n - m : 0);
}
