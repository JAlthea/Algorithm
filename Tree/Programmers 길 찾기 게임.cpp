#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> tree;    // { value, { left_value, right_value } }
unordered_map<int, int> findIndex;    // { value, index + 1 }
vector<pair<int, int>> nodes;    // { value, level }
vector<vector<int>> result;

void preorder(int node) {
    if (node < 0) return;
    result[0].push_back(findIndex[node]);
    preorder(tree[node].first);
    preorder(tree[node].second);
}

void postorder(int node) {
    if (node < 0) return;
    postorder(tree[node].first);
    postorder(tree[node].second);
    result[1].push_back(findIndex[node]);
}

int makeTree(pair<int, int> root, int index, int size) {
    tree[root.first] = { -1, -1 };
    if (size <= 0) return -1;
    if (size == 1) return root.first;
    
    int rootIndex = -1, leftSize = 0, rightSize = 0, nextLevel = 0;
    pair<int, int> leftRoot = { -1, -1 }, rightRoot = { -1, -1 };

    for (int i = index; i < index + size; ++i) {    //root index
        if (root.first == nodes[i].first) rootIndex = i;
	if (nextLevel < nodes[i].second && root.second != nodes[i].second) nextLevel = nodes[i].second;
    }
    
    for (int i = index; i < index + size; ++i) {    //leftRoot, rightRoot
        if (nextLevel == nodes[i].second && root.first > nodes[i].first) leftRoot = nodes[i];
	else if (nextLevel == nodes[i].second && root.first < nodes[i].first) rightRoot = nodes[i];
    }
    
    leftSize = rootIndex - index;
    rightSize = size - 1 - leftSize;
    
    if (leftRoot.first != -1) tree[root.first].first = makeTree(leftRoot, index, leftSize);
    if (rightRoot.first != -1) tree[root.first].second = makeTree(rightRoot, rootIndex + 1, rightSize);
	  return root.first;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    result.resize(2);
    int level = 0;
    pair<int, int> root;
    
    for (int i=0; i<nodeinfo.size(); ++i) {
        if (level < nodeinfo[i][1]) {
            level = nodeinfo[i][1];
            root = { nodeinfo[i][0], nodeinfo[i][1] };
        }
        findIndex[nodeinfo[i][0]] = i + 1;
        nodes.push_back({ nodeinfo[i][0], nodeinfo[i][1] });
    }
    sort(nodes.begin(), nodes.end(), cmp);
    
    int index = 0, size = nodes.size();
    makeTree(root, index, size);
    preorder(root.first);
    postorder(root.first);
    return result;
}
