#include <bits/stdc++.h>

int main() {
    int l, a, b, c, d;
    std::cin >> l >> a >> b >> c >> d;
    std::cout << l - max(a % c ? a / c + 1 : a / c, b % d ? b / d + 1 : b / d);
}
