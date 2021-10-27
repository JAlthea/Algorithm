#include <vector>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int size = cookie.size();
    if (size == 1)
        return 0;
    
    for (int i = 0; i < size - 1; ++i) {
        int preIndex = i;
        int postIndex = i + 1;
        int preSum = cookie[i];
        int postSum = cookie[i + 1];
        
        while (true) {
            if (preSum == postSum)
                answer = preSum > answer ? preSum : answer;
            
            if (preIndex > 0 && preSum <= postSum)
                preSum += cookie[--preIndex];
            else if (postIndex < size - 1 && preSum > postSum)
                postSum += cookie[++postIndex];
            else
                break;
        }
    }
    
    return answer;
}
