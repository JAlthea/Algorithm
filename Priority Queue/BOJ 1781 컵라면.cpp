#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> & a, pair<int, int> & b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

struct myCmp {
	bool operator()(pair<int, int> & a, pair<int, int> & b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), cmp);

	priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq;
	pq.push(arr[0]);

	for (int i = 1, deadline = 1; i < n; ++i) {
		if (deadline >= arr[i].first) {
			if (pq.top().second >= arr[i].second)
				continue;

			pq.pop();
			--deadline;
		}

		pq.push(arr[i]);
		++deadline;
	}

	int ret = 0;
	while (!pq.empty()) {
		ret += pq.top().second;
		pq.pop();
	}

	cout << ret;
}
