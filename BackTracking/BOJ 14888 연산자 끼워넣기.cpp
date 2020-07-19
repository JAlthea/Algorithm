#include <ios>
#include <vector>
using namespace std;

int d[4], Max = -1e9 - 1, Min = 1e9 + 1;

void backTrackingExpr(vector<int> &v, int pos, int result)
{
	for (int i = 0; i < 4; i++)
	{
		if (d[i] == 0)
			continue;
		
		int tmp = result;
		if (i == 0)
			tmp += v[pos];
		else if (i == 1)
			tmp -= v[pos];
		else if (i == 2)
			tmp *= v[pos];
		else if (i == 3)
			tmp /= v[pos];

		if (pos == v.size() - 1)
		{
			if (tmp > Max)
				Max = tmp;
			if (tmp < Min)
				Min = tmp;
			return;
		}
		else
		{
			d[i]--;
			backTrackingExpr(v, pos + 1, tmp);
			d[i]++;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < 4; i++)
		scanf("%d", &d[i]);

	backTrackingExpr(v, 1, v[0]);
	printf("%d\n%d", Max, Min);
}
