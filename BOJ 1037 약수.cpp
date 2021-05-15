#import <bits/stdc++.h>
int n, d[50];
int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &d[i]);
    std::sort(d, d + n);
    printf("%d", d[0] * d[n - 1]);
}
