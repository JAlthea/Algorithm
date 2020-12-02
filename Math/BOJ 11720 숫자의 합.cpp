#include <iostream>
using namespace std;

int main()
{
	int n, t, sum = 0;
	string m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		t = m.at(i) - '0';
		sum += t;
	}
	cout << sum;
}
