#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; ++i)
        scanf("%d", &h[i]);
    
    stack<int> remains;
    int result = 0;
    for (int i = 0; i < n + 1; ++i) {
        while (!remains.empty() && h[remains.top()] >= h[i]) {
            int now = remains.top();  remains.pop();
            
            int width = -1;
            if (remains.empty())
                width = i;
            else
                width = (i - remains.top() - 1);
            
            result = max(result, width * h[now]);
        }
        
        remains.push(i);
    }
    
    printf("%d", result);
}
