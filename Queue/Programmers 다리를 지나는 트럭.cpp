#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int k = 0; 
    int i = 0;
    int now_weight = 0;
    queue<int> q;
    
    while (i < truck_weights.size() || !q.empty()) {
        
        if (k >= bridge_length) {
            while (!q.empty() && q.front() == 0)
                q.pop();
            
            now_weight -= q.front(); q.pop();
            k = 0;
            
            if (!q.empty()) {
                int tmp = bridge_length - 1;
                while (!q.empty() && q.front() == 0) {
                    q.pop();
                    tmp--;
                }
                
                if (tmp <= 0)
                    tmp = 0;
                k = tmp;
            }
        }
        
        if (now_weight + truck_weights[i] <= weight) {
            q.push(truck_weights[i]);
            now_weight += truck_weights[i];
            ++i;
        }
        else if (!q.empty() && q.size() < bridge_length)
            q.push(0);
        
        ++k;
        ++answer;
    }
    
    return answer;
}
