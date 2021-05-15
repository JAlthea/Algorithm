#import <ios>

int n, a, b, c;
int main() {
  scanf("%d%d%d", &n, &a, &b);
  while (a - b) a = (a + 1) / 2, b = (b + 1) / 2, c++;
  printf("%d", c);
}
