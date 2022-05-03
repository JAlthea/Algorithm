#include <bits/stdc++.h>
using namespace std;

int d[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) { 
        return 1;
    }
    
    if (a > 20 || b > 20 || c > 20) {
        return 1048576;
    }
    
    int &ret = d[a][b][c];
    if (ret != 0) {
        return ret;
    }
    
    if (a < b && b < c) {
        return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    
    return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    int a, b, c;
    
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) { 
            break;
        }
        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}
