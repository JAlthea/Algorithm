#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(),scoville.end());
    while (!pq.empty()) {   
        int a = pq.top();
        if (a >= K)
            return answer;
        
        pq.pop();
        if (pq.empty())
            return -1;
        
        int b = pq.top();
        pq.pop();
        pq.push(a + 2 * b);
        ++answer;
    }
}
