#import <ios>
int e, s, m, a, b, c, i;
int main()
{
  for (scanf("%d%d%d", &e, &s, &m); i<7980; ++i)
  {
    ++a %= 16; ++b %= 29; ++c %= 20;
    if (!a) ++a;
    if (!b) ++b;
    if (!c) ++c;
    if (e == a && s == b && m == c) printf("%d", i + 1), i = 9999;
  }
}
