#include <cstdio>
#include <cmath>

int Turret(int x1, int y1, int r1, int x2, int y2, int r2)
{
    if (x1 == x2 && y1 == y2 && r1 == r2) 
        return -1;

    int d1 = pow(r1 + r2, 2);
    int d2 = pow(r1 - r2, 2);
    double result = pow(x1 - x2, 2) + pow(y1 - y2, 2);

    if (d1 == result || d2 == result) 
        return 1;
    if (d1 > result && d2 < result) 
        return 2;
    
    return 0;
}

int main()
{
    int x1, y1, r1, x2, y2, r2, T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        printf("%d\n", Turret(x1, y1, r1, x2, y2, r2));
    }
}
