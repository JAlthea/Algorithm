#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n < 3) {
        cout << (n + 1) * 2;
        return 0;
    }
    
    long long a = b = 1;
    for (int i = 3; i <= n; ++i) {
        long long temp = b;
        b = a + b;
        a = temp;
    }
    
    cout << 2 * a + 4 * b;
}
