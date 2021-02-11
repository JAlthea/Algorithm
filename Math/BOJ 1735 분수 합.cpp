#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    return b ? GCD(b, a % b) : a;
}

int main()
{
    int a, b, c, d, x, y, z;
    cin >> a >> b >> c >> d;
    x = a * d + c * b;
    y = b * d;
    z = GCD(x, y);
    cout << x / z << ' ' << y / z;
}
