#include <vector>
#include <climits>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int dist[101][101];
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = (i == j ? 0 : INT_MAX);
    
    for (int i = 0; i < results.size(); ++i) {
        int from = results[i][0];
        int to = results[i][1];
        dist[from][to] = 1;
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j || dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;
                
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int countVictorys[101] = { 0 };
    int countDefeats[101] = { 0 };
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j || dist[i][j] == INT_MAX)
                continue;
            
            ++countVictorys[i];
            ++countDefeats[j];
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; ++i)
        if (countVictorys[i] + countDefeats[i] == n - 1)
            ++answer;
    
    return answer;
}
