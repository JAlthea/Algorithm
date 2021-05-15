#import <ios>
int n, p, q;
int GCD(int a, int b) { return a % b ? GCD(b, a % b) : b; }
int main()
{
    scanf("%d%d", &p, &q);
    n = GCD(p, q);
    printf("%d %d", n, p * q / n);
}
