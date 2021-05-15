#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, b, c;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin >> v[i];
    cin >> b >> c;
    long long count = n;
    for (int i=0; i<n; i++)
    {
        v[i] -= b;
        v[i] = max(v[i], 0);
        count += ceil((double)v[i] / c);
    }
    cout << count;
}
