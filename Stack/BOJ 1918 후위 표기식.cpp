#include <bits/stdc++.h>
using namespace std;

int priorityOperator(char c)
{
	if (c == '*' || c == '/') return 3;
	else if (c == '+' || c == '-') return 2;
	return 1;
}

void postfix(string &s)
{
	stack<char> st;
	for (char &c : s)
	{
		if (isalpha(c)) cout << c;
		else if (c == '(') st.push(c);
		else if (c == ')')
		{
			while (st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && priorityOperator(st.top()) >= priorityOperator(c))
			{
				cout << st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty())
	{
		if (st.top() != '(') cout << st.top();
		st.pop();
	}
}

int main()
{
	string s;
	cin >> s;
	postfix(s);
}
