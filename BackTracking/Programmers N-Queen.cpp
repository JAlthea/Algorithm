#include <vector>
using namespace std;

bool check(vector<pair<int, int>> d) {   
    for (int i = 0; i < d.size(); ++i) {
        int a = d[i].first;
        int b = d[i].second;
        
        for (int j = 0; j < d.size(); ++j) {
            if (i == j)
                continue;

            int A = d[j].first;
            int B = d[j].second;

            if (a == A || b == B || abs(a - A) == abs(b - B))
                return false;
        }
    }

    return true;
}

int solution(int n) {
    if (n == 1)
        return 1;

    vector<pair<int, int>> d;
    int sum = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; ++i) {
        d.push_back({ ++x, i });

        int a = 0, b = 0;
        while (true) {
            d.push_back({ x, y });

            if (check(d)) {
                ++x;
                y = 0;
            }
            else {
                ++y;
                if (y != n)
                    d.pop_back();
            }

            if (d.size() == n && check(d)) {
                ++sum;
                y = n;
            }

            if (y == n) {
                y = 0;
                bool breaker = false;
                while (true) {
                    if (d.size() == 1) {
                        breaker = true;
                        x = 0;
                        d.clear();
                        break;
                    }

                    pair<int, int> tmp = d.back();
                    a = tmp.first;
                    b = tmp.second;
                    d.pop_back();

                    if (b == n - 1) {
                        --x;
                        continue;
                    }
                    else {
                        x = a;
                        y = b + 1;
                        break;
                    }
                }

                if (breaker)
                    break;
            }
        }
    }

    return sum;
}