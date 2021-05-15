#include <bits/stdc++.h>
using namespace std;

void convertM(vector<bool> &arr, int number)
{
	for (int i = number - 1; i < arr.size(); i += number)
		arr[i] = !arr[i];
}

void convertF(vector<bool> &arr, int number)
{
	arr[number - 1] = !arr[number - 1];
	int left = number - 2, right = number;
	while (left >= 0 && right < arr.size())
	{
		if (arr[left] != arr[right]) break;
		arr[left] = !arr[left]; arr[right] = !arr[right];
		--left; ++right;
	}
}

int main()
{
	int n, c, t;
	cin >> n;
	vector<bool> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		if (t) arr[i] = true;
		else arr[i] = false;
	}

	cin >> c;
	int sex, number;
	for (int i = 0; i < c; ++i)
	{
		cin >> sex >> number;
		if (sex == 1) convertM(arr, number);
		else convertF(arr, number);
	}

	for (int i=0; i<n; ++i)
	{
		if (i && i % 20 == 0) cout << '\n';
		cout << (arr[i] ? 1 : 0) << ' ';
	}
}
