#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = LLONG_MAX;
    long long s = *min_element(times.begin(), times.end()) * n / times.size();
    long long e = *max_element(times.begin(), times.end()) * n / times.size();
    long long m;
    while (s <= e) {
        m = (s + e) / 2;
        long long tmp = 0;
        for (int i = 0; i < times.size(); ++i)
            tmp += m / times[i];

        if (tmp < n) {
            s = m + 1;
        }
        else {
            if (answer > m)
                answer = m;
            e = m - 1;
        }
    }

    return answer;
}
