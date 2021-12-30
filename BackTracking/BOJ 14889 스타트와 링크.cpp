#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	vector<int> choice(n, 1);
	for (int i = 0; i < (n >> 1); ++i)
		choice[i] = 0;

	const int min = 1e9;
	do {
		vector<int> A;
		vector<int> B;
		for (int i = 0; i < n; ++i)
			choice[i] ? A.push_back(i + 1) : B.push_back(i + 1);

		int a = 0, b = 0;
		for (int i = 0; i < A.size(); ++i)
			for (int j = 0; j < A.size(); ++j)
				a += v[A[i] - 1][A[j] - 1], b += v[B[i] - 1][B[j] - 1];

		if (abs(a - b) < min)
			min = abs(a - b);
	} while (next_permutation(choice.begin(), choice.end()));

	cout << min;
}
