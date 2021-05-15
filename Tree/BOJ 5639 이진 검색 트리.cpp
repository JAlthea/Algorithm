#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> tree;
vector<int> inorder;

void postorder(int node)
{
	if (node <= 0) return;
	postorder(tree[node].first);
	postorder(tree[node].second);
	cout << node << ' ';
}

int makeTree(int root, int index, int size)
{
	if (size <= 0) return -1;
	if (size == 1) return root;
	
	int leftRoot, rightRoot, leftSize, rightSize, dividedIndex = 0;
	for (int i = index + 1;  i < index + size; i++)
	{
		if (root < inorder[i])
		{
			dividedIndex = i - 1 - index;
			break;
		}
	}

	if (dividedIndex == 0)	//left or right
	{
		if (root < inorder[index + 1])	//right
		{
			rightSize = size - 1;
			rightRoot = inorder[index + 1];
			tree[root].second = makeTree(rightRoot, index + 1, rightSize);
		}
		else	//left
		{
			leftSize = size - 1;
			leftRoot = inorder[index + 1];
			tree[root].first = makeTree(leftRoot, index + 1, leftSize);
		}
	}
	else	//left and right
	{
		leftSize = dividedIndex;
		rightSize = size - 1 - leftSize;
		leftRoot = inorder[index + 1];
		rightRoot = inorder[index + 1 + leftSize];
		tree[root].first = makeTree(leftRoot, index + 1, leftSize);
		tree[root].second = makeTree(rightRoot, index + 1 + leftSize, rightSize);
	}

	return root;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, t, root, index, size;
	while (!cin.eof() && cin >> t)
		inorder.push_back(t);
	
	root = inorder[0];
	index = 0;
	size = inorder.size();
	makeTree(root, index, size);
	postorder(root);
}
