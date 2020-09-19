#include <bits/stdc++.h>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int left = 1;
    int right = k;
    int mid;
    int answer;
    while (left <= right)
    {
	mid = (left + right) / 2;
        long long cnt = 0;
	for (int i = 1; i <= n; ++i)
            cnt += std::min(mid / i, n);
        
	if (cnt < k)
            left = mid + 1;
	else
        {
            answer = mid;
            right = mid - 1;
        }
    }
    printf("%d", answer);
}
