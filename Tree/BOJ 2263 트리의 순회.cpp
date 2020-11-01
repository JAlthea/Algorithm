#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree;
unordered_map<int, int> inorderFind;
vector<int> postorder;

int makeTree(int root, int inorder_start, int postorder_start, int size)
{
	if (size <= 0) return -1;
	cout << root << ' ';
	if (size == 1) return root;

	int leftSize = inorderFind[root] - inorder_start;
	int rightSize = size - leftSize - 1;
	int leftRoot = postorder[postorder_start + leftSize - 1];
	int rightRoot = postorder[postorder_start + size - 2];

	tree[root].first = makeTree(leftRoot, inorder_start, postorder_start, leftSize);
	tree[root].second = makeTree(rightRoot, inorder_start + leftSize + 1, postorder_start + leftSize, rightSize);
	return root;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, t;
	cin >> n;
	tree.resize(n + 1);

	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		inorderFind[t] = i;
	}
    
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		postorder.push_back(t);
	}

	makeTree(t, 0, 0, n);
}
