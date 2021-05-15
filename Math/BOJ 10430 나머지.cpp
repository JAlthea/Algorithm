#import <ios>
int main()
{
  int a, b, c;
  scanf("%d%d%d",&a,&b,&c);
  printf("%d %1$d %d %2$d", (a + b) % c, a * b % c);
}
