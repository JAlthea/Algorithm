#include <bits/stdc++.h>
using namespace std;

int lower_bound_search(vector<int> &s, int start, int end, int value) {
	int mid;
	
	while (start < end) {
		mid = (start + end) / 2;
		
		if (s[mid] >= value) { 
			end = mid;
			continue;
		}
		
		start = mid + 1;
	}
	
	return end;
}

int main() {
	int n;
	scanf("%d", &n);
	
	vector<int> v(n), s(n);
	vector<pair<int, int>> answer(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}

	int preLIS = 0;
	s[preLIS] = v[0];
	answer[0] = { preLIS, s[preLIS] };
	
	for (int i = 1; i < n; ++i) {
		if (v[i] > s[preLIS]) {
			s[++preLIS] = v[i];
			answer[i] = { preLIS, v[i] };
			continue;
		}

		int pos = lower_bound_search(s, 0, preLIS, v[i]);
		s[pos] = v[i];
		answer[i] = { pos, v[i] };
	}

	printf("%d\n", preLIS + 1);
	int size = preLIS;
	stack<int> st;
	
	for (int i = n - 1; i >= 0; --i) {
		if (answer[i].first == size) {
			st.push(answer[i].second);
			--size;
		}
	}
    
	while (!st.empty()) {
		printf("%d ", st.top()); st.pop();
	}
}
