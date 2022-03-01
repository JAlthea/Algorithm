#include <bits/stdc++.h>
using namespace std;

vector<int> d[300000];
vector<long long> c;
bool isCheck[300000];
long long answer;

long long dfs(int start) {
    long long parentValue = c[start];
    long long ret = 0;
    for (int i = 0; i < d[start].size(); ++i) {
        int end = d[start][i];
        if (isCheck[end])
            continue;
        
        isCheck[end] = true;
        long long childValues = dfs(end);
        parentValue += childValues;
    }
    
    answer += abs(parentValue);
    return c[start] = parentValue;
}

// Greedy + DFS
long long solution(vector<int> a, vector<vector<int>> edges) {
    for (auto &i : a) {
        c.push_back(i);
    }
    
    for (int i = 0; i < edges.size(); ++i) {
        int start = edges[i][0];
        int end = edges[i][1];
        d[start].push_back(end);
        d[end].push_back(start);
    }
    
    isCheck[0] = true;
    if (dfs(0) + c[0])
        return -1;
    return answer;
}
