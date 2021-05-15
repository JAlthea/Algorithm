#include <bits/stdc++.h>
using namespace std;

void solution()
{
	int n;
	cin >> n;
	n += 2;

	int d[10001] = { 0 };
	for (int i = 2; i < 10001; i++)
		d[i]++;

	for (int i = 2; i < 10001; i++)
		if (d[i])
			for (int j = i + i; j < 10001; j += i)
				d[j] = 0;

	int p;
	for (int i = 2; i < 10001; i++)
	{
		if (d[i])
		{
			if (n % i == 0)
			{
				p = i;
				break;
			}
		}
	}

	int k = 0;
	for (int i = 2; i <= p; i++)
		if (d[i])
			k++;
			
	cout << k + 999 << "번 문제를 제출한다.";
}

int main()
{
	solution();
	//출력에 해당하는 문제를 풀어서 제출
}
