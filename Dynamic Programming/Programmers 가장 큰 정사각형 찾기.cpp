#include <vector>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (i && j && board[i][j])
                board[i][j] += min(min(board[i - 1][j], board[i][j - 1]), board[i - 1][j - 1]);
            if (answer < board[i][j])
                answer = board[i][j];
        }
    }
    return answer * answer;
}
