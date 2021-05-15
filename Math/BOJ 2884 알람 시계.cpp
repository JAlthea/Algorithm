#import <ios>
int h, m;
int main()
{
  scanf("%d%d", &h, &m);
  m > 44 ? m -= 45 : h ? (h--, m += 15) : (h = 23, m += 15);
  printf("%d %d",h, m);
}
