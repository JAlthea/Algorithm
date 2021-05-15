#include <algorithm>
#include <ios>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		int now = v[i] * (n - i);
		if (now > max) max = now;
	}
  
	printf("%d", max);
}
