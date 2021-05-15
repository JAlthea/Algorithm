#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> s;
int d[100001][2], size;
bool choiceFirst;

int collecting(int n)
{
    if(size - 1 == n)
    {
        if(choiceFirst)
            return 0;
        else
            return s[n];
    }

    if(size - 1 < n)
        return 0;

    if(d[n][choiceFirst] != -1)
        return d[n][choiceFirst];

    int ret = 0;
    ret = max(ret, collecting(n + 2) + s[n]);
    ret = max(ret, collecting(n + 1));
    return d[n][choiceFirst] = ret;
}

int solution(vector<int> sticker)
{
    s = sticker;
    size = sticker.size();
    memset(d, -1, sizeof(d));
    
    int answer = 0;
    choiceFirst = true;
    answer = max(answer, collecting(2) + s[0]);
    choiceFirst = false;
    answer = max(answer, collecting(1));
    
    return answer;
}
