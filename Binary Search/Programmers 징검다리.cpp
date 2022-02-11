#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    int s = 1;
    int e = distance;
    int mid;
    int answer = 0;
    
    while (s <= e) {
        mid = (s + e) / 2;
        
        int count = 0;
        int prev = 0;
        for (int i = 0; i < rocks.size(); ++i) {
            if (rocks[i] - prev < mid) {
                ++count;
                continue;
            }
            
            prev = rocks[i];
        }
        
        if (distance - prev < mid)
            ++count;
        
        if (count <= n)
        {
            answer = max(answer, mid);
            s = mid + 1;
            continue;
        }

        e = mid - 1;
    }
    
    return answer;
}
