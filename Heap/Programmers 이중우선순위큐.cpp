#include <string>
#include <vector>
#include <queue>
using namespace std;

struct pair_greater {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
};

struct pair_less {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
};

vector<int> solution(vector<string> operations) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, pair_greater> minQ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, pair_less> maxQ;
    int size = operations.size();
    vector<bool> v(size, false);
    for (int i=0; i<size; i++)
    {
        if (operations[i][0] == 'I')
        {
            string sub = operations[i].substr(2, operations[i].size() - 1);
            maxQ.push({i, stoi(sub)});
            minQ.push({i, stoi(sub)});
        }
        else if (operations[i][0] == 'D')
        {
            if (minQ.empty() || maxQ.empty())
                continue;
            
            if (operations[i][2] == '1')
            {
                if (!v[maxQ.top().first])
                {
                    v[maxQ.top().first] = true;
                    maxQ.pop();
                }
            }
            else
            {
                if (!v[minQ.top().first])
                {
                    v[minQ.top().first] = true;
                    minQ.pop();
                }
            }
        }
        
        while (!minQ.empty())
        {
            if (!v[minQ.top().first])
                break;
            minQ.pop();
        }
        
        while (!maxQ.empty())
        {
            if (!v[maxQ.top().first])
                break;
            maxQ.pop();
        }        
    }
    
    if (minQ.empty() || maxQ.empty())
        return {0, 0};
    return {maxQ.top().second, minQ.top().second};
}
