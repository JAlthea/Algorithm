#include <cmath>

int count;

void dfs(int n, int one) {
    if (n < 3 || n / (int)pow(3, ceil((double)one / 2)) == 0)
        return;
    
    if (n == 3 && one == 2) {
        ++count;
        return;
    }

    if (n % 3 == 0 && one >= 2)
        dfs(n / 3, one - 2);
    dfs(n - 1, one + 1);
}

int solution(int n) {
    count = 0;
    dfs(n, 0);
    return count;
}
