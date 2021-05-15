#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (int i = begin; i <= end; i++)
    {
        if (i == 1)
        {
            answer.push_back(0);
            continue;
        }
        
        bool check = false;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                if (i / j <= 10000000)
                {
                    answer.push_back(i / j);
                    check = true;
                    break;
                }
            }
        }
        if (!check)     //prime number
            answer.push_back(1);
    }
    
    return answer;
}
