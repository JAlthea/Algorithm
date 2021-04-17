#import <ios>
int s = 1, n;
int main() {
    scanf("%d", &n);
    while (s < n) s *= 2;
    printf("%d", 2 * n - s);
}
