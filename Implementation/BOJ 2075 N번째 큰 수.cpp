#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    
    vector<int> nowIdx(n, n - 1);
    int counter = 0;
    while (true) {
        int maxValueIndex = 0;
        int maxValue = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (maxValue < arr[nowIdx[i]][i]) {
                maxValue = arr[nowIdx[i]][i];
                maxValueIndex = i;
            }
        }
        
        ++counter;
        if (counter == n) {
            cout << maxValue;
            return 0;
        }
        
        if (nowIdx[maxValueIndex])
            --nowIdx[maxValueIndex];
    }
}
