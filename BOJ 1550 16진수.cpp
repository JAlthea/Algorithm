#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int dSum = 0;
    for (int i=s.size()-1, o=1; i>=0; --i, o*=16)
    {
        if (s[i] >= '0' && s[i] <= '9') dSum += (s[i] - 48) * o;
        else dSum += (10 + s[i] - 'A') * o;
    }
    cout << dSum;
}
