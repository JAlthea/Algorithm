#include <cstdio>

int main() {
    int ax, ay, az, cx, cy, cz;
    scanf("%d %d %d\n%d %d %d", &ax, &ay, &az, &cx, &cy, &cz);
    printf("%d %d %d", cx - az, cy / ay, cz - ax);
}
