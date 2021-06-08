#include <ios>

int x, y, a, b;
int main() {
	while (~scanf("%d %d", &a, &b)) {
		x ^= a, y ^= b;
	}
	printf("%d %d", x, y);
}
