#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
    
    vector<int> arr(n), ret(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ret[i] = arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    map<int, int> h;
    int convertValue = -1;
    int lastValue = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != lastValue)
            ++convertValue;
        
        h[arr[i]] = convertValue;
        lastValue = arr[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cout << h[ret[i]] << ' ';
    }
}
