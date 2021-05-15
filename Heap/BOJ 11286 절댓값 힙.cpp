#include <queue>
#include <ios>
using namespace std;

struct cmp
{
	bool operator()(int x, int y)
	{
		return x + y == 0 ? return x > y : abs(x) > abs(y);
	}
};

int main()
{
	int n, x;
	priority_queue<int, vector<int>, cmp> pq;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
	    scanf("%d", &x);
		if (x)
			pq.push(x);
		else
		{
			if (pq.empty())
			{
				puts("0");
				continue;
			}

			printf("%d\n", pq.top());
			pq.pop();
		}
	}
}
