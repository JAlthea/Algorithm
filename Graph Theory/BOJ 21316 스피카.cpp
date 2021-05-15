#include <bits/stdc++.h>
using namespace std;

//adhoc : 어떤 한 점에서 시작해서, 3개의 연결된 점이 있고, 그 점 중에서 하나는 더 이상 갈 곳이 없을 때, 어떤 한 점은 스피카 별

int main() {
	vector<vector<int>> edge(13);
	for (int i = 0; i < 12; ++i) {
		int s, e;
		cin >> s >> e;
		edge[s].push_back(e);
		edge[e].push_back(s);
	}

	for (int s = 1; s < 13; ++s) {
		if (edge[s].size() != 3)
			continue;

		bool checkStar[4] = { false };
		for (int i = 0; i < edge[s].size(); ++i) {
			int e = edge[s][i];
			if (edge[e].size() == 1)
				checkStar[1] = true;
			else if (edge[e].size() == 2)
				checkStar[2] = true;
			else if (edge[e].size() == 3)
				checkStar[3] = true;
		}

		bool isSpica = true;
		for (int i = 1; i < 4; ++i) {
			if (!checkStar[i]) {
				isSpica = false;
				break;
			}
		}

		if (isSpica) {
			cout << s;
			return 0;
		}
	}
}
