#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    vector<int> v = nums;
    sort(v.begin(), v.end());
    
    int answer = 0;
    int max = 0;
    for (int i = 0; i < v.size(); i++) {
        if (answer >= v.size() / 2)
            break;
        
        if (max < v[i]) {
            max = v[i];
            answer++;
        }
    }
    
    return answer;
}
