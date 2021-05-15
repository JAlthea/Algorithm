#import <ios>
int n, s, m = 100;
int main()
{
    while (~scanf("%d", &n)) n % 2 ? s += n, m = m > n ? n : m : 0;
    s ? printf("%d %d", s, m) : puts("-1");
}
