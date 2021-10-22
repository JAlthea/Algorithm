#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct cmp {
	bool operator()(const pair<int, int> & a, const pair<int, int> & b) const {
		return a.second > b.second;
	}
};

int solution(vector<vector<int>> land, int height) {
    int n = land.size();
    vector<pair<int, int>> edge[n * n + 1];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < n - 1) {
                int c = abs(land[i][j] - land[i + 1][j]);
                if (c <= height)
                    c = 0;
                edge[i * n + j + 1].push_back({ (i + 1) * n + j + 1, c });
            }
            if (i > 0) {
                int c = abs(land[i][j] - land[i - 1][j]);
                if (c <= height)
                    c = 0;
                edge[i * n + j + 1].push_back({ (i - 1) * n + j + 1, c });
            }
            if (j < n - 1) {
                int c = abs(land[i][j] - land[i][j + 1]);
                if (c <= height)
                    c = 0;
                edge[i * n + j + 1].push_back({ i * n + j + 1 + 1, c });
            }
            if (j > 0) {
                int c = abs(land[i][j] - land[i][j - 1]);
                if (c <= height)
                    c = 0;
                edge[i * n + j + 1].push_back({ i * n + j - 1 + 1, c });
            } 
        }
    }

    int result = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> dist;
    bool visited[100001] = { false };
    dist.push({1, 0});
    
    for (int i = 1; i <= n * n; ++i) {
        int now = -1, minDist = INT_MAX;
        
        while (!dist.empty()) {
            now = dist.top().first;
            if (!visited[now]) {
                minDist = dist.top().second;
                break;
            }
            dist.pop();
        }

        result += minDist;
        visited[now] = true;
        for (auto &e : edge[now])
            dist.push(e);
    }

    return result;
}
