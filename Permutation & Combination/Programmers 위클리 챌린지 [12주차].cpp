#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> orders(dungeons.size());
    
    for (int i = 0; i < orders.size(); ++i) {
        orders[i] = i;
    }
    
    do {
        int nowK = k;
        int nowCount = 0;
        
        for (int i = 0; i < dungeons.size(); ++i) {
            int minK = dungeons[orders[i]][0];
            int costK = dungeons[orders[i]][1];
            
            if (minK <= nowK) {
                nowK -= costK;
                ++nowCount;
                continue;
            }
            break;
        }
        
        answer = max(answer, nowCount);        
    } while (next_permutation(orders.begin(), orders.end()));
    
    return answer;
}
