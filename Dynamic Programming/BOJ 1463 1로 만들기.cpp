#include <ios>

inline int f(int n) {
    return n < 2 ? 0 : std::min(f(n / 2) + n % 2, f(n / 3) + n % 3) + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
}
