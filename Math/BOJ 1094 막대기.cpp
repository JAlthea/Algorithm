#import <ios>
int n, a = 64, c;
int main()
{
  scanf("%d", &n);
  while (n) n < a ? 0 : (c++, n -= a), a /= 2;
  printf("%d", c);
}
