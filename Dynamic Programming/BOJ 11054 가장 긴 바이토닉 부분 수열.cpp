#include <bits/stdc++.h>

int n, a[1001], d[1001][3];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; ++i) {    // Left -> Right
		int now = a[i];
		int maxCount = 0;
		for (int j = 1; j < i; ++j) {
			if (a[i] > a[j]) {
				maxCount = std::max(maxCount, d[j][0]);
			}
		}
		
		d[i][0] = maxCount + 1;
	}
	
	for (int i = n; i >= 1; --i) {    // Right -> Left
		int now = a[i];
		int maxCount = 0;
		for (int j = n; j > i; --j) {
			if (a[i] > a[j]) {
				maxCount = std::max(maxCount, d[j][1]);
			}
		}
		
		d[i][1] = maxCount + 1;
	}

	int maxSeq = 0;
	for (int i = 1; i <= n; ++i) {    // Left + Right
		d[i][2] = d[i][0] + d[i][1] - 1, maxSeq = std::max(maxSeq, d[i][2]);
	}
	
	printf("%d", maxSeq);
}
