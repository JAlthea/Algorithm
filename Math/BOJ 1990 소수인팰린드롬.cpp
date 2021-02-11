#include <bits/stdc++.h>
using namespace std;

int d[10001];
vector<int> primeRoot, palins;

bool isPrime(int a)
{
	for (int i = 0; a >= primeRoot[i] * primeRoot[i]; ++i)
		if (a % primeRoot[i] == 0) return false;
	return true;
}

void makePalin()
{
	vector<string> ret;
	int left_right = 0;
	while (left_right <= 9)
	{
		ret.push_back(to_string(left_right) + to_string(left_right));
		++left_right;
	}

	left_right = 0;
	while (left_right <= 9)
	{
		int center = 0;
		while (center <= 9)
		{
			ret.push_back(to_string(left_right) + to_string(center) + to_string(left_right));
			++center;
		}
		++left_right;
	}

	int prevSize = 0;
	int nowSize = ret.size();
	while (ret.back().size() < 8)
	{
		bool isExit = false;
		for (int i = prevSize; i < nowSize; ++i)
		{
			if (ret[i].size() == 7)
			{
				isExit = true;
				break;
			}
            
			left_right = 0;
			while (left_right <= 9)
			{
				ret.push_back(to_string(left_right) + ret[i] + to_string(left_right));
				++left_right;
			}
		}
        
		if (isExit) break;
		prevSize = nowSize;
		nowSize = ret.size();
	}

	for (int i = 0; i < ret.size(); ++i)
	{
		if (ret[i].front() == '0') continue;
		palins.push_back(stoi(ret[i]));
	}

	palins.push_back(5);
	palins.push_back(7);
	sort(palins.begin(), palins.end());
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i <= 10000; ++i)
	{
		if (d[i] == false)
		{
			primeRoot.push_back(i);
			for (int j = i + i; j <= 10000; j += i)
				d[j] = true;
		}
	}
	makePalin();

	int a, b;
	cin >> a >> b;
	for (int i = 0; i < palins.size(); ++i)
		if (palins[i] >= a && palins[i] <= b && isPrime(palins[i])) cout << palins[i] << '\n';
	cout << -1;
}
