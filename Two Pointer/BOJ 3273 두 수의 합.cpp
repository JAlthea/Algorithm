#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cin >> x;
    
    sort(arr.begin(), arr.end());
    
    int count = 0;
    for (int left = 0, right = n - 1; left < right;) {
        if (arr[left] + arr[right] == x) {
            ++count;
        }
        
        if (arr[left] + arr[right] > x) {
            --right;
        }
        else {
            ++left;
        }
    }
    
    cout << count;
}
