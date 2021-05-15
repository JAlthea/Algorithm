#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, t;
	cin >> n;
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		pq.push(t);
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	int a = pq.top(); pq.pop();
	long long now = a + pq.top(); pq.pop();
	long long sum = now;
	pq.push(now);
	while (!pq.empty()) {
		a = pq.top(); pq.pop();
		if (pq.empty()) break;
		now = a + pq.top(); pq.pop();
		sum += now;
		pq.push(now);
	}

	cout << sum;
}
