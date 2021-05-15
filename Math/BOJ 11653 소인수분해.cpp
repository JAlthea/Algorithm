#import <ios>
int n, i = 2;
int main()
{
    for(scanf("%d", &n); n!=1; ++i)
    {
        if(n % i == 0)
        {
            printf("%d ", i);
            n /= i;
            i = 1;
        }
    }
}
