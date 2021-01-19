#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    return b ? GCD(b, a % b) : a;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; ++i)
            cin >> arr[i];
        
        long long GCD_Sum = 0;
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
                GCD_Sum += GCD(arr[i], arr[j]);
        
        cout << GCD_Sum << '\n';
    }
}
