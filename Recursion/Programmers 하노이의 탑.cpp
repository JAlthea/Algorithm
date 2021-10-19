#include <vector>
using namespace std;

vector<vector<int>> ret;

void recur(int n, int a, int b, int c) {
    if (n == 0) return;
    recur(n - 1, a, c, b);
    ret.push_back({ a, c });
    recur(n - 1, b, a, c);
}

vector<vector<int>> solution(int n) {
    recur(n, 1, 2, 3);
    return ret;
}
