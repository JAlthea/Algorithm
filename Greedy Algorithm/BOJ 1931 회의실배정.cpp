#include <vector>
#include <ios>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v(n, { 0, 0 });
	for(int i = 0; i < v.size(); i++)
		scanf("%d%d", &v[i].first, &v[i].second);
	sort(v.begin(), v.end(), cmp);

	int now = v[0].second;
	int count = 1;
	for(int i = 1; i < v.size(); i++)
    {
		if(now <= v[i].first)
        {
 		    count++;
            now = v[i].second;
        }
    }
	printf("%d", count);
}
