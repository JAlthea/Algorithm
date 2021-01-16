#include <ios>

int n, k, a, d[1001];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=2; i<=n; ++i)
    {
        if (!d[i])
        {
            ++a;
            if (a == k)
            {
                printf("%d", i);
                break;
            }
            
            for (int j=i+i; j<=n; j+=i)
            {
                if (!d[j])
                {
                    ++d[j];
                    ++a;
                    if (a == k)
                    {
                        printf("%d", j);
                        return 0;
                    }
                }
            }
        }
    }
}
