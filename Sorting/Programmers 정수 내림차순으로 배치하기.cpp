#include <string>
#include <algorithm>
using namespace std;

bool cmp(long long a, long long b) {
    return a > b;
}

long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), cmp);
    return stoll(s);
}
