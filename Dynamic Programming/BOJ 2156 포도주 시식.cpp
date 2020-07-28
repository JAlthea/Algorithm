#import <iostream>
#import <algorithm>
using namespace std;

int d[10001][3], c[10001], n, i=1;

int main()
{
	for(cin >> n; i<=n; i++) cin >> c[i];
	for(i=1; i<=n; i++)
	{
		d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
		d[i][1] = d[i-1][0] + c[i];
		d[i][2] = d[i-1][1] + c[i];
	}
	cout<< max(d[n][0], max(d[n][1], d[n][2]));
}
