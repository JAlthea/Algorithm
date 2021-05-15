#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<pair<int, int>> tree;

pair<int, int> init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node].first = arr[start];
		tree[node].second = arr[end];
		return tree[node];
	}

	int mid = (start + end) / 2;
	pair<int, int> leftNode = init(node * 2, start, mid);
	pair<int, int> rightNode = init(node * 2 + 1, mid + 1, end);
	tree[node].first = min(leftNode.first, min(rightNode.first, min(leftNode.second, rightNode.second)));
	tree[node].second = max(leftNode.first, max(rightNode.first, max(leftNode.second, rightNode.second)));
	return tree[node];
}

pair<int, int> min_max(int node, int start, int end, int left, int right)
{
	if (start > right || end < left) return { 0, 0 };
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	pair<int, int> leftNode = min_max(node * 2, start, mid, left, right);
	pair<int, int> rightNode = min_max(node * 2 + 1, mid + 1, end, left, right);
	pair<int, int> ret;

	if (leftNode.first == 0)
	{
		ret.first = min(rightNode.first, rightNode.second);
		ret.second = max(rightNode.first, rightNode.second);
	}
	else if (rightNode.first == 0)
	{
		ret.first = min(leftNode.first, leftNode.second);
		ret.second = max(leftNode.first, leftNode.second);
	}
	else
	{
		ret.first = min(leftNode.first, min(rightNode.first, min(leftNode.second, rightNode.second)));
		ret.second = max(leftNode.first, max(rightNode.first, max(leftNode.second, rightNode.second)));
	}

	return ret;
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
		pair<int, int> p = min_max(1, 0, n - 1, a - 1, b - 1);
		cout << p.first << ' ' << p.second << '\n';
	}
}
