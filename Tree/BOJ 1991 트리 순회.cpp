#include <bits/stdc++.h>
using namespace std;

void preorder(vector<pair<char, char>> &tree, char node)
{
	if (node == '.') return;
	cout << node;
	preorder(tree, tree[node - 'A'].first);
	preorder(tree, tree[node - 'A'].second);
}

void inorder(vector<pair<char, char>> &tree, char node)
{
	if (node == '.') return;
	inorder(tree, tree[node - 'A'].first);
	cout << node;
	inorder(tree, tree[node - 'A'].second);
}

void postorder(vector<pair<char, char>> &tree, char node)
{
	if (node == '.') return;
	postorder(tree, tree[node - 'A'].first);
	postorder(tree, tree[node - 'A'].second);
	cout << node;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<char, char>> tree(26);
	while (n--)
	{
		char parent, leftChild, rightChild;
		cin >> parent >> leftChild >> rightChild;
		tree[parent - 'A'] = { leftChild, rightChild };
	}
	preorder(tree, 'A'); cout << '\n';
	inorder(tree, 'A'); cout << '\n';
	postorder(tree, 'A');
}
