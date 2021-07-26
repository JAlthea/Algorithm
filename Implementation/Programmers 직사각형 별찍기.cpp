#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; cout << '\n', ++i)
        for (int j = 0; j < a; cout << '*', ++j);
}
