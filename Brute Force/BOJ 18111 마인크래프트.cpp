#include <bits/stdc++.h>
using namespace std;

int n, m, b, d[501][501];

int simulation(int h) {
    int remainBlock = b;
    int retTime = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
			if (h > d[i][j]) {
				remainBlock -= h - d[i][j];
				retTime += h - d[i][j];
			}
			else if (h < d[i][j]) {
				remainBlock += d[i][j] - h;
				retTime += (d[i][j] - h) * 2;
			}
        }
    }
    
	if (remainBlock < 0)
		return -1;
    return retTime;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> b;
    
    int minH = 256;
    int maxH = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> d[i][j];
            minH = min(minH, d[i][j]);
            maxH = max(maxH, d[i][j]);
        }
    }
    
    int minTime = INT_MAX;
    int dh = 0;
    for (int h = minH; h <= maxH; ++h) {
        int retTime = simulation(h);
        if (retTime != -1 && minTime >= retTime) {
            minTime = retTime;
            dh = max(dh, h);
        }
    }
    
    cout << minTime << ' ' << dh;
}
