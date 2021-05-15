#import <bits/stdc++.h>
int main()
{
    int n, i;
    scanf("%d",&n);
    std::vector<std::vector<int>> d(n, std::vector<int>(2));
    for(i=0; i<n; i++)
        scanf("%d%d", &d[i][1], &d[i][0]);
    std::sort(d.begin(), d.end());
    for(i=0; i<n; i++)
        printf("%d %d ",d[i][1], d[i][0]);
}
