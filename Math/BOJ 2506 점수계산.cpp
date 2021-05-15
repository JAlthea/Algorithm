#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ret = 0;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ++count;
            ret += count;
        }
        else
        {
            count = 0;
        }
    }
    cout << ret;
}
