#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int size = stones.size();
    long long s = 1;
    long long e = *max_element(stones.begin(), stones.end());
    long long m;
    
    while (s <= e) {
        m = (s + e) / 2;
        
        int count = 0;
        bool isPossible = true;
        
        for (int i = 0; i < size; ++i) {
            if (stones[i] < m)
                ++count;    // 이게 연속으로 k번 만큼 있으면 건널 수 없다는 판정.
            else
                count = 0;
            
            if (count == k) {
                isPossible = false;
                break;
            }
        }

        if (isPossible) {
            if (answer < m)
                answer = m;
            s = m + 1;
            continue;
        }
        
        e = m - 1;
    }

    return answer;
}
