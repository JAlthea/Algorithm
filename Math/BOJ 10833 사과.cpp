#include <iostream>
using namespace std;

int main()
{
    int n, a, b, ret = 0;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        ret += b - (b / a * a);
    }
    cout << ret;
}
