#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string tmp = "";
	int k = 0;
	while (s[k] >= '0' && s[k] <= '9')
		tmp += s[k++];
	int min = stoi(tmp);
	int size = s.size();
	for (int i = k; i < size;)
	{
		if (s[i] == '-')
		{
			i++;
			int now = 0;
			while (s[i] != '-' && i < size)
			{
				if (s[i] == '+') i++;
				string n = "";
				while (s[i] >= '0' && s[i] <= '9')
					n += s[i++];
				now += stoi(n);
			}
			min -= now;
		}
		else if (s[i] == '+')
		{
			i++;
			string n = "";
			while (s[i] >= '0' && s[i] <= '9')
				n += s[i++];
			min += stoi(n);
		}
	}
	cout << min;
}
