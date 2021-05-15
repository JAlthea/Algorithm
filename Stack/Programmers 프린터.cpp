#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> tmp = priorities;
    vector<vector<int>> s(tmp.size(), vector<int>(2));
    for (int i=0; i<tmp.size(); i++)
    {
        s[i][0] = tmp[i];
        s[i][1] = i;
    }
    sort(tmp.begin(), tmp.end(), greater<int>());
    
    int k = 0;
    int count = 0;
    while (!tmp.empty())
    {
        vector<int> v = s.front();
        
        if (v[0] == tmp[k])
        {
            s.erase(s.begin());
            count++;
            k++;
            if (v[1] == location)
                break;
        }
        else
        {
            s.erase(s.begin());
            s.push_back(v);  
        }
    }
    
    return count;
}
