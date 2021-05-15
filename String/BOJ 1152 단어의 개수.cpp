#include <iostream>
#include <cstring>
using namespace std;

int c; char p[1000000]; char *q;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin.getline(p, 1000000);
    q = strtok(p, " ");
    while (q) { c++; q = strtok(NULL, " "); }
    cout << c;
}
