#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), pSum(n + 1);
    for (int i=0; i<n; ++i)
        cin >> arr[i];
    
    for (int i=1; i<=n; ++i)
        pSum[i] = pSum[i - 1] + arr[i - 1];
    
    int maxValue = INT_MIN;
    for (int i=1; i<=n - k + 1; ++i)
        maxValue = max(maxValue, pSum[i + k - 1] - pSum[i - 1]);
    
    cout << maxValue;
}
