#include <bits/stdc++.h>
using namespace std;

int n, m;

int dfs(vector<vector<int>> &v) {
	vector<bool> visited(n + 1, false);
	stack<int> s;
	s.push(1);
	int count = 0;
	
	while (!s.empty()) {
		int now = s.top(); s.pop();
		
		if (visited[now])
			continue;
		visited[now] = true;
		
		++count;
		
		for (int i = n; i > 0; --i)
			if (v[now][i])
				s.push(i);
	}
	
	return count - 1;
}

int main() {
	scanf("%d%d", &n, &m);
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
	int a, b;
	
	while (~scanf("%d%d", &a, &b)) {
		++v[a][b];
		++v[b][a];
	}
	
	printf("%d", dfs(v));
}
