#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long long> lanes(n - 1), prices(n), leftMins(n + 1, INT_MAX);
    long long total = 0;
    
    for (int i = 0; i < lanes.size(); ++i) {
        cin >> lanes[i];
    }
    
    for (int i = 0; i < prices.size(); ++i) {
        cin >> prices[i];
        leftMins[i + 1] = min(leftMins[i], prices[i]);
        if (i < prices.size() - 1) total += lanes[i] * leftMins[i + 1];
    }
    
    cout << total;
}
