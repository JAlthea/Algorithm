#include <cstdio>
int x, y, w, h, a, b;
int main()
{
    scanf("%d%d%d%d", &x, &y, &w, &h);
    a = x < w - x ? x : w - x;
    b = y < h - y ? y : h - y;
    printf("%d", a < b ? a : b);
}
