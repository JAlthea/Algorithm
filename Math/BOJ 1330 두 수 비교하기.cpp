#import <ios>
int a, b;
int main()
{
  scanf("%d%d", &a, &b);
  puts(a > b ? ">" : a < b ? "<" : "==");
}
