#import <iostream>
#import <stack>
#import <string>
using namespace std;

bool isCorrect(string &str)
{
	stack<char> s;
	char c;
	for(int i=0; i<str.size(); ++i)
	{
		c = str[i];
		if(c == '(')
			s.push(c);
		else
		{
			if(s.empty())
				return false;
			s.pop();
		}
	}
	if(!s.empty())
		return false;
	return true;
}

int main(int n)
{
	string s;
	cin >> n;
	while(n--)
	{
		cin >> s;
		puts(isCorrect(s) ? "YES" : "NO");
	}
}
