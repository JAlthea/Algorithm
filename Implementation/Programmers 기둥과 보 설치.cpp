#include <bits/stdc++.h>
using namespace std;

bool isPossibleCreatePi(int x, int y, set<pair<int, int>> &pi, set<pair<int, int>> &bo) {
    //바닥위에 있거나
    if (y == 0)
        return true;
       
    //보의 한쪽 끝 부분에 있거나
    if (bo.find({x, y}) != bo.end() || bo.find({x - 1, y}) != bo.end())
        return true;
    
    //다른 기둥위에 있거나
    if (pi.find({x, y - 1}) != pi.end())
        return true;
    
    return false;
}

bool isPossibleCreateBo(int x, int y, set<pair<int, int>> &pi, set<pair<int, int>> &bo) {
    //한쪽 끝 부분이 기둥 위에 있거나
    if (pi.find({x, y - 1}) != pi.end() || pi.find({x + 1, y - 1}) != pi.end())
        return true;
    
    //양쪽 끝 부분이 다른 보와 동시에 연결되어 있거나
    if (bo.find({x - 1, y}) != bo.end() && bo.find({x + 1, y}) != bo.end())
        return true;
    
    return false;
}

bool isPossibleDeletePi(int x, int y, set<pair<int, int>> &pi, set<pair<int, int>> &bo) {
    pi.erase({x, y});
    
    for (auto i : pi)
    {
        if (!isPossibleCreatePi(i.first, i.second, pi, bo))
        {
            pi.insert({x, y});
            return false;
        }
    }
    
    for (auto i : bo)
    {
        if (!isPossibleCreateBo(i.first, i.second, pi, bo))
        {
            pi.insert({x, y});
            return false;
        }        
    } 
    
    pi.insert({x, y});
    return true;
}

bool isPossibleDeleteBo(int x, int y, set<pair<int, int>> &pi, set<pair<int, int>> &bo) {
    bo.erase({x, y});
    
    for (auto i : pi)
    {
        if (!isPossibleCreatePi(i.first, i.second, pi, bo))
        {
            bo.insert({x, y});
            return false;
        }
    }
    
    for (auto i : bo)
    {
        if (!isPossibleCreateBo(i.first, i.second, pi, bo))
        {
            bo.insert({x, y});
            return false;
        }
    }
    
    bo.insert({x, y});
    return true;
}

bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0] && a[1] == b[1])
        return a[2] < b[2];
    
    if (a[0] == b[0])
        return a[1] < b[1];
    
    return a[0] < b[0];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    const int PI = 0;
    const int BO = 1;
    const int DELETE = 0;
    const int CREATE = 1;
    vector<vector<int>> answer;
    set<pair<int, int>> pi;
    set<pair<int, int>> bo;
    
    for (int i=0; i<build_frame.size(); i++)
    {
        vector<int> c = build_frame[i];
        int x = c[0];
        int y = c[1];
        int type = c[2];
        int command = c[3];
        
        if (type == PI)    //해당 좌표점과 위쪽까지 포함
        {
            if (command == CREATE)
            {
                if (isPossibleCreatePi(x, y, pi, bo))
                    pi.insert({x, y});
            }
            else
            {
                if (isPossibleDeletePi(x, y, pi, bo))
                    pi.erase({x, y});
            }
        }
        else if (type == BO)    //해당 좌표점과 오른쪽까지 포함
        {
            if (command == CREATE)
            {
                if (isPossibleCreateBo(x, y, pi, bo))
                    bo.insert({x, y});
            }
            else
            {
                if (isPossibleDeleteBo(x, y, pi, bo))
                    bo.erase({x, y});
            }            
        }
    }
    
    //pi, bo에 있는 원소를 answer에 담고 기준에 따라 정렬
    for (auto i : pi)
        answer.push_back({i.first, i.second, PI});
    for (auto i : bo)
        answer.push_back({i.first, i.second, BO});
    
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}
