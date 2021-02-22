#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
vector<long long> arr, tree;

long long init(int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	long long leftNode = init(node * 2, start, mid) % M;
	long long rightNode = init(node * 2 + 1, mid + 1, end) % M;
	return tree[node] = leftNode * rightNode % M;
}

long long update(int node, int start, int end, int index, long long value)
{
	if (start > index || end < index) return tree[node];
	if (start == end) return tree[node] = value;
	int mid = (start + end) / 2;
	long long leftNode = update(node * 2, start, mid, index, value) % M;
	long long rightNode = update(node * 2 + 1, mid + 1, end, index, value) % M;
	return tree[node] = leftNode * rightNode % M;
}

long long mul(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 1;
	if (left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	long long leftNode = mul(node * 2, start, mid, left, right) % M;
	long long rightNode = mul(node * 2 + 1, mid + 1, end, left, right) % M;
	return leftNode * rightNode % M;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	long long n, m, k, a, b, c;
	cin >> n >> m >> k;

	arr.resize(n);
	tree.resize(1 << ((int)ceil(log2(n)) + 1));
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	init(1, 0, n - 1);
	for (int i = 0; i < m + k; ++i)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, 0, n - 1, b - 1, c);
			arr[b - 1] = c;
			continue;
		}
    
		cout << mul(1, 0, n - 1, b - 1, c - 1) << '\n';
	}
}
