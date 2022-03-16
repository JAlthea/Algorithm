#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int sum = INT_MAX;
    int leftIndex = 0, rightIndex = n - 1;
    
    for (int left = 0, right = n - 1; left < right;) {
        if (abs(arr[left] + arr[right]) < abs(sum)) {
            sum = arr[left] + arr[right];
            leftIndex = left;
            rightIndex = right;
        }
        
        if (abs(arr[left]) > abs(arr[right])) {
            ++left;
        }
        else {
            --right;
        }
    }
    
    cout << arr[leftIndex] << ' ' << arr[rightIndex];
}
