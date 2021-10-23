#include <bits/stdc++.h>
using namespace std;

long long findEnd(map<long long, long long> & m, long long n) {
    if (m.find(n) == m.end())
        return n;
    return m[n] = findEnd(m, m[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    map<long long, long long> m;
    
    for (int i = 0; i < room_number.size(); ++i) {
        long long n = room_number[i];
        if (m.find(n) == m.end()) {
            answer.push_back(n);
            m[n] = findEnd(m, n + 1);
        }
        else {
            long long tmp = findEnd(m, n);
            answer.push_back(tmp);
            m[tmp] = findEnd(m, tmp + 1);
        }
    }

    return answer;
}
