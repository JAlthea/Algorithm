#import <ios>

int n, p, q = 1e6;
int main()
{
  p = -q;
  scanf("%d", &n);
  while (~scanf("%d", &n))
  {
    if (p < n) p = n;
    if (q > n) q = n;
  }
  printf("%d %d", q, p);
}
