#include <string>
#include <vector>
using namespace std;

void rotateKey(vector<vector<int>> &m) {
    int N = m.size();
    for (int x = 0; x < N / 2; ++x) {
        for (int y = x; y < N - x - 1; ++y) {
            int tmp = m[x][y];
            m[x][y] = m[y][N - 1 - x];
            m[y][N - 1 - x] = m[N - 1 - x][N - 1 - y];
            m[N - 1 - x][N - 1 - y] = m[N - 1 - y][x];
            m[N - 1 - y][x] = tmp;
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int hole = 0;
    for (int i = 0; i < lock.size(); ++i)
        for (int j = 0; j < lock.size(); ++j)
            if (lock[i][j] == 0)
                ++hole;
    
    int K = key.size();
    int L = lock.size();
    for (int k = 0; k < 4; ++k) { //rotate
        for (int i = 1 - K; i < L; ++i) { //lock
            for (int j = 1 - K; j < L; ++j) {
                int count = 0;
                bool isExit = false;
                
                for (int x = 0; x < key.size(); ++x) { //key
                    if (i + x < 0 || i + x >= lock.size())
                        continue;

                    for (int y = 0; y < key.size(); ++y) {
                        if (j + y < 0 || j + y >= lock.size())
                            continue;

                        if (key[x][y] == 1 && lock[i + x][j + y] == 1) {
                            isExit = true;
                            break;
                        }
                        
                        if (key[x][y] == 1 && lock[i + x][j + y] == 0)
                            ++count;
                    }
                }
                
                if (count == hole)
                    return true;
            }
        }
        
        rotateKey(key);
    }
    
    return false;
}
