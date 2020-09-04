#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T, n;
	cin >> T;
	while(T--)
	{
		string s, tmp;
		cin >> s;
		cin >> n;
		cin >> tmp;
		deque<int> d;
		for(int i = 0; i < tmp.size(); ++i)
		{
			if(tmp[i] < 48 || tmp[i] > 57)
				continue;

			string now = "";
			while(tmp[i] > 47 && tmp[i] < 58)
			{
				now += tmp[i];
				i++;
			}
			d.push_back(stoi(now));
		}
	
		bool reverse = false;
		bool check = false;
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == 'R')
				reverse = !reverse;
			else
			{
				if(d.empty())
				{
					cout << "error\n";
					check = true;
					break;
				}

				if(reverse)
					d.pop_back();
				else
					d.pop_front();
			}
		}
		if(check)
			continue;

		int size = d.size();
		cout << '[';
		for(int i = 0; i < size; ++i)
		{
			if(reverse)
			{
				if(i == size - 1)
					cout << d.back();
				else
					cout << d.back() << ',';
				d.pop_back();
			}
			else
			{
				if(i == size - 1)
					cout << d.front();
				else
					cout << d.front() << ',';
				d.pop_front();
			}
		}
		cout << "]\n";
	}
}
