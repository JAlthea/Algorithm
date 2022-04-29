#import <ios>
#import <algorithm>

int n, k, i, j, d[10001], s[101];

int main() {
	for (scanf("%d%d", &n, &k); i < n; ++i) {
		scanf("%d", &s[i]);
	}
	
	std::sort(s,s + n);

	d[0] = 1;
	for (i = 0; i < n; ++i) {
		for (j = s[i]; j <= k; ++j) {
			d[j] += d[j - s[i]];
		}
	}

	printf("%d", d[k]);
}
