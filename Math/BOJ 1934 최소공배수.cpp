#import <ios>
int p, q, n, t;
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
int main()
{
  scanf("%d", &t);
  while (t--)
    scanf("%d%d", &p, &q), n = p > q ? GCD(p, q) : GCD(q, p), printf("%d\n", p * q / n);
}
