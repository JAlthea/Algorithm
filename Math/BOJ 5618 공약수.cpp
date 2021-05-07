#include <bits/stdc++.h>
using namespace std;

int d[3];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    
    for (int i = 1; i <= *min_element(d, d + n); ++i) {
        bool isCD = true;
        for (int j = 0; j < n; ++j) {
            if (d[j] % i) {
                isCD = false;
                break;
            }
        }
        
        if (isCD) {
            cout << i << '\n';
        }
    }
}
