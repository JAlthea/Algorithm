#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    vector<int> s = works;
    long long answer = 0;
    int k = 0;
    
    sort(s.begin(), s.end(), greater<int>());       

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] - s[i + 1] == 0 && i != s.size() - 1)
            continue;

        if (n >= (s[i] - s[i + 1]) * (i + 1) && i != s.size() - 1) {
            n -= (s[i] - s[i + 1]) * (i + 1);
        }
        else {
            int d = n;
            int m = n;
            int now = s[i];

            while (d > i + 1) {
                m %= i + 1;
                d /= i + 1;

                now = s[i] - d;
                if (i == 0 || now <= 0)
                    break;
            }

            if (now <= 0)
                answer = 0;
            else
                answer = pow(now - 1, 2) * m + pow(now, 2) * (i + 1 - m);

            k = i + 1;
            break;
        }
    }

    for (int i = k; i < s.size(); ++i)
        answer += pow(s[i], 2);

    return answer;
}
