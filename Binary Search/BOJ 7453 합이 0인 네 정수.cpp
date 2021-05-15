#include <bits/stdc++.h>
using namespace std;

int A[4000], B[4000], C[4000], D[4000];
int AB[16000000], CD[16000000];

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	int ab = 0;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			AB[ab++] = A[a] + B[b];
		}
	}

	int cd = 0;
	for (int c = 0; c < n; ++c) {
		for (int d = 0; d < n; ++d) {
			CD[cd++] = C[c] + D[d];
		}
	}

	sort(CD, CD + n * n);

	long long ret = 0;
	for (int i = 0; i < n * n; ++i) {
		pair<int*, int*> p = equal_range(CD, CD + n * n, -AB[i]);
		ret += p.second - p.first;
	}

	cout << ret;
}
