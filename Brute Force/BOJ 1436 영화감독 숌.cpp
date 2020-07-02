#import <bits/stdc++.h>
using namespace std;

int n, i = 666,k = 1;
bool check(string s)
{
    int k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (k == 3)
            return true;
        s[i] == '6' ? k++ : k = 0;
    }
    if (k == 3)
	    return true;
    return false;
}

int main()
{
    cin >> n;
    while (k < n)
    {
        i++;
        if (check(to_string(i)))
            k++;
    }
    cout << i;
}
