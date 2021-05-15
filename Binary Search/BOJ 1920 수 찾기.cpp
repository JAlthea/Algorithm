#include <cstdio>
#include <algorithm>

int n, i, t, d[100001];
int main()
{
	for(scanf("%d", &n); i<n; ++i) scanf("%d", &d[i]);
	std::sort(d, d + n);
	scanf("%d", &i);
	while(i--) scanf("%d", &t), printf("%d\n", std::binary_search(d, d + n, t));
}
