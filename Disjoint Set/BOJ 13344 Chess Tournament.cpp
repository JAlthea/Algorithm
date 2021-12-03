#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int s[50001], h[50001];

int findSet(int e) {
	if (s[e] == e)
		return e;
	return s[e] = findSet(s[e]);
}

void unionSet(int a, int b) {
	int x = findSet(a);
	int y = findSet(b);
	if (x == y)
		return;

	if (h[x] < h[y]) {
		s[x] = y;
		h[y] += h[x];
	}
	else {
		s[y] = x;
		h[x] += h[y];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, from, to, count = 0;
	bool isPossible = true;
	string op;

	cin >> n >> m;
	unordered_set<int> setRoot;
	vector<unordered_set<int>> edge(n);
	vector<vector<int>> tmp(n);
	vector<int> indegree(n, 0);
	for (int i = 0; i < n; ++i) {
		s[i] = i;
		h[i] = 1;
	}

	for (int i = 0; i < m; ++i) {
		cin >> from >> op >> to;
		if (op == ">")
			tmp[from].push_back(to);
		else if (op == "=")
			unionSet(from, to);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < tmp[i].size(); ++j) {
			int a = findSet(i);
			int b = findSet(tmp[i][j]);
			if (a == b) {
				isPossible = false;
				break;
			}
            
			setRoot.insert(a);
			setRoot.insert(b);
			if (!edge[a].count(b)) {
				indegree[b]++;
				edge[a].insert(b);
			}
		}
	}

	queue<int> q;
	for (int & i : setRoot)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		count++;
		for (int next : edge[now]) {
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
    
	if (!isPossible)
		cout << "inconsistent";
	else
		cout << (count == setRoot.size() ? "consistent" : "inconsistent");
}
