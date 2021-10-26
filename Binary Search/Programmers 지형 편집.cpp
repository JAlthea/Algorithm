#include <vector>
#include <algorithm>
using namespace std;

long long f(vector<int> tmp, int h) {
    long long result = 0;
    
    for (int i = 0; i < tmp.size(); ++i) {
        if (tmp[i] >= h)
            break;
        result += h - tmp[i];
    }
    
    return result;
}

long long g(vector<int> tmp, int h) {
    long long result = 0;
    
    for (int i = tmp.size() - 1; i >= 0; --i) {
        if (tmp[i] <= h)
            break;
        result += tmp[i] - h;
    }
    
    return result;
}

long long solution(vector<vector<int>> land, int P, int Q) {
    int N = land.size();
    double a = (double) Q * N * N / (P + Q);
    
    vector<int> tmp(N * N);
    for (int i = 0, k = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            tmp[k++] = land[i][j];
    
    sort(tmp.begin(), tmp.end());
    int maxH = tmp[tmp.size() - 1];
    int minH = tmp[0];
    int midH = -1;
    long long upCount = 0;
    long long downCount = 0;
    long long midCount = 0;
    double A = 0;

    while (1) {   
        midH = (maxH + minH) >> 1;
        upCount = f(tmp, midH + 1);
        downCount = f(tmp, midH);
        A = abs(upCount - downCount);
        
        if (midH == minH)
            break;
        if (a < A)
            maxH = midH;
        else if (a >= A)
            minH = midH;
    }
    
    upCount = f(tmp, minH + 1);
    downCount = f(tmp, minH);
    A = abs(upCount - downCount);
    
    while (a >= A) {
        ++minH;
        upCount = f(tmp, minH + 1);
        downCount = f(tmp, minH);
        A = abs(upCount - downCount);
    }
    
    return P * f(tmp, minH) + Q * g(tmp, minH);
}
