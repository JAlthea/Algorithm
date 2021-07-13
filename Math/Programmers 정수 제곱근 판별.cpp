#include <cmath>
using namespace std;

long long solution(long long n) {
    long long x = sqrt(n);
    return x * x == n ? (x + 1) * (x + 1) : -1;
}
