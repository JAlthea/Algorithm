#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long g, x = 1, y = 1;
	cin >> g;
	
	bool isPossible = false;
	do
	{
        long long d = x * x - y * y;
		if (d == g)
		{
			long long rx = (long long)sqrt(y * y + g);
			if (rx * rx == x * x)
			{
				cout << x << '\n';
				isPossible = true;
			}
			++y;
		}
		else if (d > g) ++y;
		else ++x;
		
	} while (x + y <= g);

	if (!isPossible) cout << -1;
}
