#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> arrSum(n + 1, 0);
    for (int i=1; i<=n; ++i)
        cin >> arr[i];
    
    for (int i=1; i<=n; ++i)
        arrSum[i] = arrSum[i - 1] + arr[i];
    
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        cout << arrSum[b] - arrSum[a - 1] << '\n';
    }
}
