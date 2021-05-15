#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, m = 99999;
	priority_queue<int, vector<int>, less<int>> l;
	priority_queue<int, vector<int>, greater<int>> r;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		if (m == 99999)
		{
			m = x;
			l.push(x);
			printf("%d\n", m);
			continue;
		}

		if (m < x)
			r.push(x);
		else
			l.push(x);

		if (abs((int)l.size() - (int)r.size()) > 1)
		{
			if (l.size() > r.size())
			{
				int t = l.top();
				l.pop();
				r.push(t);
			}
			else
			{
				int t = r.top();
				r.pop();
				l.push(t);
			}
		}

		if (l.size() > r.size())
			m = l.top();
		else if (l.size() < r.size())
			m = r.top();
		else
			m = min(l.top(), r.top());

		printf("%d\n", m);
	}
}
