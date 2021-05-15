#include <iostream>
using namespace std;

int a, b, c, s;
int main()
{
    cin >> a >> b >> c;
    if (a == b && b == c) s = 1e4 + a * 1e3;
    else if (a == b || a == c || b == c) s = 1e3 + (b - c ? a : b) * 1e2;
    else s = max(a, max(b, c)) * 1e2;
    cout << s;
}
