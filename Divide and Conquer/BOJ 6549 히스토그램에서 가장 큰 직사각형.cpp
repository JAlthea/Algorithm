#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        vector<int> h(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &h[i]);
        }
    
        stack<int> remains;
        long long result = 0;
        
        for (int i = 0; i < n + 1; ++i) {
            while (!remains.empty() && h[remains.top()] >= h[i]) {
                int now = remains.top(); remains.pop();
                int width = -1;
                if (remains.empty()) {
                    width = i;
                }
                else {
                    width = (i - remains.top() - 1);
                }
            
                result = max(result, (long long)width * h[now]);
            }
        
            remains.push(i);
        }
    
        printf("%lld\n", result);
    }
}
