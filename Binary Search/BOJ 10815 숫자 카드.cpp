#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	
	sort(a.begin(), a.end());
	
	for (int i = 0; i < m; ++i)
		cout << (binary_search(a.begin(), a.end(), b[i]) == true ? "1 " : "0 ");
}