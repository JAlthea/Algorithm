#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	if (n >= k)
	{
		cout << 0;
		return 0;
	}

	unordered_set<int> used;
	vector<int> arr(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> arr[i];
		if (used.size() < n) used.insert(arr[i]);
	}

	int ret = 0;
	for (int i = n; i < k; ++i)
	{
		if (used.find(arr[i]) != used.end()) continue;

		int outPlug;
		unordered_set<int> fastInput;
		for (int j = i + 1; j < k; ++j)
		{
			if (fastInput.size() == n - 1) break;
			if (used.find(arr[j]) != used.end()) fastInput.insert(arr[j]);
		}

		for (auto &p : used)
		{
			if (fastInput.find(p) == fastInput.end())
			{
				outPlug = p;
				break;
			}
		}

		used.erase(outPlug);
		used.insert(arr[i]);
		++ret;
	}

	cout << ret;
}
