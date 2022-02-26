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
    vector<vector<int>> lock2(lock.size() + 2 * key.size() - 2, vector<int>(lock.size() + 2 * key.size() - 2, -1));
    
    for (int i = 0; i < lock.size(); ++i) {
        for (int j = 0; j < lock.size(); ++j) {
            if (lock[i][j] == 0)
                ++hole;
            
            lock2[i + key.size() - 1][j + key.size() - 1] = lock[i][j];
        } 
    }

    for (int k = 0; k < 4; ++k) {    // Rotate
        for (int i = 0; i < lock2.size() - key.size(); ++i) {    // Lock
            for (int j = 0; j < lock2.size() - key.size(); ++j) {
                int count = 0;
                bool isExit = false;
                
                for (int x = 0; x < key.size(); ++x) {    // Key
                    for (int y = 0; y < key.size(); ++y) {
                        if (key[x][y] == 1 && lock2[i + x][j + y] == 1) {
                            isExit = true;
                            break;
                        }
                        
                        if (key[x][y] == 1 && lock2[i + x][j + y] == 0)
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
