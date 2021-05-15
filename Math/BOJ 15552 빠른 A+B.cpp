#include <cstdio>

int main()
{
	int t, a, b;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &a, &b);
		printf("%d ", a + b);
	}
}

/*
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << a + b << ' ';
	}
}
*/
