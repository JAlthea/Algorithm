#import <ios>
int n, a[42], i;
int main()
{
  while (~scanf("%d", &n)) a[n % 42]++;
  for (n = i = 0; i<42; ++i) a[i] ? n++ : 0;
  printf("%d", n);
}
