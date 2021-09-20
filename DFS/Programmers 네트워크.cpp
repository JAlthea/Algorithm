#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    int answer = 0;
    
    for (int k = 0; k < n; ++k) {
        if (visited[k])
            continue;
        
        ++answer;
        stack<int> s;
        s.push(k);
        visited[k] = true;
        while (!s.empty()) {
            int now = s.top(); s.pop();
            for (int i = 0; i < n; ++i) {
                if (now != i && computers[now][i] && !visited[i]) {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    
    return answer;
}
