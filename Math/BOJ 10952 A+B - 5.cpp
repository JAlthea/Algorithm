#import <ios>

int main()
{
  int a, b;
  while (scanf("%d%d", &a, &b))
  {
    if (!a) break;
    printf("%d\n",a + b);
  }
}
