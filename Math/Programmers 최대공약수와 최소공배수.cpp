#include <vector>
using namespace std;

int GCD(int a, int b) {
    return a % b ? GCD(b, a % b) : b;
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

vector<int> solution(int n, int m) {
    return { GCD(n, m), LCM(n, m) };
}
