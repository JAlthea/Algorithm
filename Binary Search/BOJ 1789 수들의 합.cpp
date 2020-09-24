#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int s, n, min, max, mid;
    cin >> s;
    n = 1;
    min = 0; max = 4294967295;
    while (min <= max)
    {
        mid = (min + max) / 2;
        long long sum = (long long)mid * (mid + 1) / 2;
        
        if (sum > s)
            max = mid - 1;
        else
        {
            if (n < mid)
                n = mid;
            min = mid + 1;
        }
    }
    cout << n;
}
