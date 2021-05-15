#include <bits/stdc++.h>
using namespace std;

vector<int> arr, tree;

int init(int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int min(int node, int start, int end, int left, int right)
{
	if (start > right || end < left) return INT_MAX;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(min(node * 2, start, mid, left, right), min(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;

	arr.resize(n);
	tree.resize(1 << ((int)ceil(log2(n)) + 1));
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	init(1, 0, n - 1);
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		cout << min(1, 0, n - 1, a - 1, b - 1) << '\n';
	}
}
