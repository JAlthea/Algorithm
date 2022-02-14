#include <bits/stdc++.h>
using namespace std;

int n;
double cache[16][65536], dist[16][16];

double TSP(int from, int visited) {
	if (visited == (1 << n) - 1) 
		return dist[from][0];
	
	ouble &ret = cache[from][visited];
	if (ret) 
		return ret;
	ret = 1e8;
	
	for (int to = 0; to < n; ++to) {
		if (visited & (1 << to)) 
			continue;
		ret = min(ret, TSP(to, visited | (1 << to)) + dist[from][to]);
	}
	
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	n = N;
	vector<pair<int, int>> pos(n);
	for (int i = 0; i < n; ++i)
		cin >> pos[i].first >> pos[i].second;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dist[i][j] = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));

	cout << fixed;
	cout.precision(7);
	cout << TSP(0, 1);
}
