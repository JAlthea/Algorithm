#include <bits/stdc++.h>
using namespace std;

int lower_bound_search(vector<int> &s, int value) {
    int mid, start = 0, end = s.size() - 1;

    while (start < end) {
        mid = (start + end) / 2;
        
        if (s[mid] >= value) {
            end = mid;
            continue;
        }
        
        start = mid + 1;
    }

    return end;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n + 1);
    vector<int> s;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);

    s.push_back(v[1]);
    for (int i = 2; i <= n; ++i) {
        if (v[i] > s.back()) {
            s.push_back(v[i]);
            continue;
        }
        
        s[lower_bound_search(s, v[i])] = v[i];
    }

    printf("%d", s.size());
}