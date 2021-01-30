#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; ++i) cin >> arr[i];
    if (next_permutation(arr.begin(), arr.end())) for (auto &c : arr) cout << c << ' ';
    else cout << -1;
}
