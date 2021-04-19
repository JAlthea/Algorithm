#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n ; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    sort(arr.begin(), arr.end());
    
    int ret = 1;
    int pqSize = 1;
    int k = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(arr[0].second);
    while (k < n) {
        int endTime = pq.top();
        if (arr[k].first < endTime) {
            pq.push(arr[k].second);
            ++pqSize;
        }
        else {
            while (!pq.empty() && pq.top() <= arr[k].first) {
                pq.pop();
                --pqSize;
            }
            
            pq.push(arr[k].second);
            ++pqSize;
        }
        
        ret = max(ret, pqSize);
        ++k;
    }
    
    cout << ret;
}
