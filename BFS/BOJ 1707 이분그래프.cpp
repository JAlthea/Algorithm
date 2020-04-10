#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int k, v, e;
	cin >> k;
	while (k--)
	{
		cin >> v >> e;
		vector<vector<int>> s(v + 1);
		for (int i = 0; i < e; i++)    //Connecting Info
		{
			int a, b;
			cin >> a >> b;
			s[a].push_back(b);
			s[b].push_back(a);
		}

		bool isNo = false;
		vector<int> checkVertex(v + 1, -1);
		for (int i = 1; i <= v; i++) //All vertex
		{
			if (checkVertex[i] != -1)
				continue;
			checkVertex[i] = i % 2;
            
			queue<pair<int, int>> q;
			q.push({ i, i % 2 });
			while (!q.empty())
			{
				if (isNo)
					break;

				pair<int, int> p = q.front(); q.pop();
				int t = p.first;
				int color = p.second;

				for (int j = 0; j < s[t].size(); j++)
				{
					if (checkVertex[s[t][j]] == -1)
					{
						q.push({ s[t][j], (color + 1) % 2 });
						checkVertex[s[t][j]] = (color + 1) % 2;
					}
					else if (checkVertex[s[t][j]] == color)
					{
						isNo = true;
						break;
					}
				}
			}

			if (isNo)
			{
				cout << "NO\n";
				break;
			}
		}

		if (!isNo)
			cout << "YES\n";
	}
}
