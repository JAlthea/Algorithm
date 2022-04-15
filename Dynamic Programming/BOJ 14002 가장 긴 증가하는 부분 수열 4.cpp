#include <bits/stdc++.h>

int n, d[1001], s[1001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
	}

	for (int i = 1; i <= n; ++i) {
		int now = d[i];
		int maxCount = 0;
		for (int j = 1; j < i; ++j) {
			if (d[i] > d[j]) {
				maxCount = std::max(maxCount, s[j]);
			}
		}

		s[i] = maxCount + 1;
	}
	
	int maxLength = *std::max_element(s, s + n + 1);
	printf("%d\n", maxLength);

	std::stack<int> st;
	for (int i = n; i > 0; --i) {
		if (maxLength == 0) {
			break;
		}
		
		if (s[i] == maxLength) {
			st.push(d[i]);
			--maxLength;
		}
	}
	
	while (!st.empty()) {
		printf("%d ", st.top()); st.pop();
	}
}
