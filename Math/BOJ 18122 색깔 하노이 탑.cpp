#import <iostream>
int n, m = 1, c = 1e9 + 7;
int main() {
    std::cin >> n;
    for (; 2 + n--; m >= c ? m %= c : m) {
        m *= 2;
    }
    std::cout << m - 5;
}
