#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int sup = stock;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i=1, j=0; i<k; i++)
    {
        sup--;
        if (i == dates[j])
            pq.push(supplies[j++]);
        
        if (sup == 0)
        {
            sup = pq.top(); pq.pop();
            answer++;
        }
    }
    
    return answer;
}
