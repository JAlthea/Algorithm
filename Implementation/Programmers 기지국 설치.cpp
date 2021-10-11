#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int value = 0;
    
    for (int i = 0; i < stations.size(); ++i) {
        int gap = stations[i] - w - 1 - value;
        gap = max(gap, 0);
        answer += (int)ceil((double)gap / (w * 2 + 1));
        value = stations[i] + w;
    }
    
    answer += (int)ceil((double)(n - value) / (w * 2 + 1));
    return answer;
}
