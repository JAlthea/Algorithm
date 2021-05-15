#import <bits/stdc++.h>
int main()
{
    int a[3];
    while (scanf("%d%d%d", &a[0], &a[1], &a[2]))
    {
        if (!a[0]) break;
        std::sort(a, a+3);
        puts(a[0] * a[0] + a[1] * a[1] - a[2] * a[2] ? "wrong" : "right");
    }
}
