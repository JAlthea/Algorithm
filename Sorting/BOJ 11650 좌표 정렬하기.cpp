#import <ios>
#import <vector>
#import <algorithm>
using namespace std;

int main()
{
    int n, i;
    scanf("%d", &n);
    vector<vector<int>> d(n, vector<int>(2, 0));
    for (i=0; i<n; i++)
        scanf("%d%d", &d[i][0], &d[i][1]);
    sort(d.begin(), d.end());
    for (i=0; i<n; i++)
        printf("%d %d\n", d[i][0], d[i][1]);
}
