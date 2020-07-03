#include <cstdio>
int i, n, m[1001], a[1001], s[1001];
int main()
{
    for (scanf("%d", &n); i < n; i++)
        scanf("%d", &m[i]);

    for (i = 0; i < n; i++)
        if (m[i] >= 0)
            a[m[i]]++;
        else
            s[m[i] * -1]++;

    for (i = 1000; i > 0; i--)
        if (s[i] != 0)
            printf("%d\n", -i);
	
    for (i = 0; i < 1001; i++)
        if (a[i] != 0)
            printf("%d\n", i);
}
