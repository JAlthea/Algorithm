#import <ios>
int a, s = 1, n[10];
int main()
{
  for (;~scanf("%d", &a) ? s *= a : (n[s % 10]++, s /= 10););
  while (s < 10) printf("%d\n", n[s++]);
}
