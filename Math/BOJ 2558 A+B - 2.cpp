#include <cstdio>

inline int mySum(const int &a, const int &b) {
	return a + b;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", mySum(a, b));
}
