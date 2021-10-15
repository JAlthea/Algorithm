#include <vector>
using namespace std;

long long solution(int n) {
    long long d[2002] = { 0, 1, 2, 3 };
    
    for (int i = 4; i <= n; ++i) {
        d[i] = d[i - 1] + d[i - 2];
        if (d[i] > 1234566)
            d[i] %= 1234567;
    }
    
    return d[n];
}
