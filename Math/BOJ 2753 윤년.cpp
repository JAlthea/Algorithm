#import <ios>
int main(int n)
{
  scanf("%d", &n);
  puts(n % 4 == 0 && n % 100 || n % 400 == 0 ? "1" : "0");
}
