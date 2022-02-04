#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<long long> times(n);
    for (int i = 0; i < n; ++i)
        cin >> times[i];
    
    long long answer = LLONG_MAX;
    long long s = *min_element(times.begin(), times.end()) * m / times.size();
    long long e = *max_element(times.begin(), times.end()) * m / times.size();
    long long mid;

    while (s <= e) {
        mid = (s + e) / 2;

        long long tmp = 0;
        for (int i = 0; i < n; ++i)
            tmp += mid / times[i];
        
        if (tmp < m) {
            s = mid + 1;
            continue;
        }

        if (answer > mid)
            answer = mid;
        e = mid - 1;
    }
    
    cout << answer;
}