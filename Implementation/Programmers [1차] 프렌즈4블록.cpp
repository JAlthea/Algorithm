#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checkSameBlock(vector<string> & v, int a, int b) {
    int value = v[a][b];
    for (int i = a; i < a + 2; ++i)
        for (int j = b; j < b + 2; ++j)
            if (value != v[i][j])
                return false;
    
    return true;
}

int check2x2(int m, int n, vector<string> & v) {
    vector<string> tmp(v.begin(), v.end());
    for (int i = 0; i < m - 1; ++i)
        for (int j = 0; j < n - 1; ++j)
            if (v[i][j] != 0 && checkSameBlock(v, i, j))
                tmp[i][j] = tmp[i][j + 1] = tmp[i + 1][j] = tmp[i + 1][j + 1] = 1;
    
    int count = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (tmp[i][j] == 1)
                count++, v[i][j] = 0;
    
    return count;
}

void dropBox(int m, int n, vector<string> & v) {
    for (int j = 0; j < n; ++j) {
        int k = m - 1;
        while (k >= 0 && v[k][j] != 0)
            --k;
        
        if (k < 0)
            continue;
        
        int start = k;
        while (k >= 0 && v[k][j] == 0)
            --k;
        
        if (k < 0)
            continue;
        
        swap(v[k][j], v[start][j]);
        --j;
    }
}

void print(int m, int n, vector<string> & v) {
    for (int i = 0; i < m; puts(""), ++i)
        for (int j = 0; j < n; ++j)
            v[i][j] ? printf("%c ", v[i][j]) : printf("0 ");          
    puts("");
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (1) {
        int count = check2x2(m, n, board);
        if (count == 0)
            break;
        
        answer += count;
        dropBox(m, n, board);
    }
    
    return answer;
}
