#include <iostream>
#include <ctime>
#include <string>
#include <stack>
using namespace std;

bool check(string &src)
{
	stack<char> s;
	char c, t;
	for (int i=0; i<src.size(); ++i)
	{
		c = src[i];
		if (c == '(' || c == '[')
			s.push(c);
		else if (c == ')' || c == ']')
		{
			if (s.empty())
				return false;
			t = s.top();
			s.pop();
			if ((c == ')' && t == '['))
				return false;
			if ((c == ']' && t == '('))
				return false;
		}
	}
	if (!s.empty())
		return false;
	return true;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s == ".")
			break;
		puts(check(s) ? "yes" : "no");
	}
}
