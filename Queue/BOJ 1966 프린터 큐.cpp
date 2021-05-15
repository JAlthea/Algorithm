#include <ios>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T, n, m;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		m++;

		queue<pair<int, int>> q;
		vector<int> v(n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i]);
			q.push({ i + 1, v[i] });
		}
		sort(v.begin(), v.end(), greater<int>());
		int k = 0;
		int index = 1;
		while(!q.empty())
		{
			if(v[k] == q.front().second)
			{
				if(q.front().first == m)
					break;
				q.pop();
				index++;
				k++;
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}

		printf("%d\n", index);
	}
}
