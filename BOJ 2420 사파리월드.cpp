#include <ios>
int main()
{
    long long n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld", n > m ? n - m : m - n);
}
