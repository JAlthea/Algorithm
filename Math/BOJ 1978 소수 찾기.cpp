#import <ios>
int n, i, j, c, d[1001] = {0, 1};
int main()
{
    for(i=2; i*i<=1000; i++)
        if(!d[i])
            for(j=i*i; j<1001; j+=i)
                d[j]++;
    scanf("%d", &n);
    while (n--)
        scanf("%d", &i), !d[i] ? c++ : c;
    printf("%d", c);
}
