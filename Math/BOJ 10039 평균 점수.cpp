#import <ios>
int n, s;
int main()
{
  while (~scanf("%d", &n))
    s += n < 40 ? 40 : n;
  printf("%d", s / 5);
}
