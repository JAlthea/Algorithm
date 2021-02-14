#include <bits/stdc++.h>
using namespace std;

vector<long long> arr, tree;

long long init(int node, int start, int end)
{
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int index, long long dif)
{
    if (start > index || end < index) return;
    tree[node] += dif;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, dif);
    update(node * 2 + 1, mid + 1, end, index, dif);
}

long long sum(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
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
            update(1, 0, n - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
            continue;
        }
        
        cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
    }
}
