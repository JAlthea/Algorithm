#import <ios>
int a, b, i;
int main() {
  scanf("%d%d", &a, &b);
  a -= a % 100;
  while ((a + i) % b) i++;
  printf("%02d", i);
}
