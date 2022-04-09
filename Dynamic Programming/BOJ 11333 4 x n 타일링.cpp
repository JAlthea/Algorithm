#include <cstdio>

const int M = 1e9 + 7;
long long d[10001];

long long tilingFourByN(int n) {
	if (n < 0) {
		return 0;
	}
	
	if (n == 1) {
		return 2;
	}
	
	if (n == 3) 
		return d[n] = 3;
	}

	if (d[n]) {
		return d[n];
	}

	for (int i = 2; i <= n; ++i) {
		if ((i - 1) % 3 == 0) {
			d[i] = (2 * tilingFourByN(i - 1) + tilingFourByN(i - 3)) % M;
			continue;
		}
		
		d[i] = (tilingFourByN(i - 1) + tilingFourByN(i - 3)) % M;
	}

	return d[n];
}

int main() {
	int t, n;
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		tilingFourByN(n);
		n % 3 ? puts("0") : printf("%lld\n", d[n]);
	}
}
