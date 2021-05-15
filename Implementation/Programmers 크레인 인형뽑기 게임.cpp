#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> bucket;
    for (int i=0; i<moves.size(); i++)
    {
        int index = moves[i];
        for (int j=0; j<board.size(); j++)
        {
            if (board[j][index - 1] == 0)
                continue;
            
            bucket.push_back(board[j][index - 1]);
            board[j][index - 1] = 0;
            break;
        }   
    }

    int answer = 0;
    for (int k=1; k<bucket.size(); k++)
    {
        if (bucket[k - 1] == bucket[k])
        {
            bucket.erase(bucket.begin() + k - 1, bucket.begin() + k + 1);
            answer += 2;
            k = 0;
        }
    }
    
    return answer;
}
