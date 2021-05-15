#import <ios>
char a[4],b[4];
int q, w, e, r, o;
int main()
{
  scanf("%s%s", a, b);
  o = atoi(a);
  q = o * (b[2] - 48);
  w = o * (b[1] - 48);
  e = o * (b[0] - 48);
  r = q + 10 * w + 100 * e;
  printf("%d\n%d\n%d\n%d", q, w, e, r);
}
