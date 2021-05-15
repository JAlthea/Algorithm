#include <bits/stdc++.h>
using namespace std;

int d[14], aMoney, bMoney, aCount, bCount, aSum, bSum;

int main()
{
	cin >> aMoney;
	bMoney = aMoney;
	for (int i = 0; i < 14; ++i)
	{
		cin >> d[i];
		aCount += aMoney / d[i];
		aMoney %= d[i];
	}

	int prev = d[0], up = 0, down = 0;
	for (int i = 1; i < 14; ++i)
	{
		if (d[i] > prev) ++up, down = 0;
		else if (d[i] < prev) ++down, up = 0;
		else up = down = 0;

		if (up >= 3) bMoney += bCount * d[i], bCount = 0;
		else if (down >= 3) bCount += bMoney / d[i], bMoney %= d[i];

		prev = d[i];
	}

	aSum = aMoney + d[13] * aCount;
	bSum = bMoney + d[13] * bCount;

	if (aSum > bSum) cout << "BNP";
	else if (aSum < bSum) cout << "TIMING";
	else cout << "SAMESAME";
}
