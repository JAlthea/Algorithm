#include <cstdio>

const int M = 1e9;
int d[10], c[10], n, s;

int main() {
	for (int i = 1; i < 10; ++i) { 
		++d[i], ++c[i];
	}
	
	scanf("%d", &n);
	
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (!j) { 
				d[j] = c[1];
			}
			else if (j == 9) {
				d[j] = c[8];
			}
			else {
				d[j] = c[j - 1] + c[j + 1];
			}
			
			d[j] %= M;
		}
		
		for (int j = 0; j < 10; ++j) {
			c[j] = d[j];
		}
	}
	
	for (int i = 0; i < 10; ++i) {
		s = (s + d[i]) % M;
	}
	
	printf("%d", s);
}
