#import <ios>
int n, s = 1;
int main()
{
  for (scanf("%d", &n); n; s *= n--);
  printf("%d", s);
}
