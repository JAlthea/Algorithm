#include <unordered_set>
using namespace std;

int solution(int N, int number)
{
	if(N == number)
		return 1;
        
	int answer = -1;
	int tmp = 0;
	unordered_set<int> s[8];
	for(int i = 0; i < 8; ++i)
	{
		tmp = 10 * tmp + 1;
		s[i].insert(tmp * N);
	}
    
	for(int i = 1; i < 8; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			for(auto op1 : s[j])
			{
				for(auto op2 : s[i - j - 1])
				{
					s[i].insert(op1 + op2);
					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);
					if(op2)
						s[i].insert(op1 / op2);
				}
			}
		}
        
		if(s[i].count(number) > 0)
		{
			answer = i + 1;
			break;
		}
	}
    
	return answer;
}
