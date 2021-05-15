#import <ios>
int n, t;
int main()
{
  while (~scanf("%d", &n)) t += n * n;
  printf("%d", t % 10);
}
