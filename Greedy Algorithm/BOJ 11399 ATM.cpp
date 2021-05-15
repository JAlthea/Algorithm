#import <ios>

int a, t, i, s, d[1001];

int main()
{
    for(scanf("%d", &a); i<a; i++)
        scanf("%d", &t), d[t]++;
    
    t = 0; s = a;
    for(i=1; i<1001; i++)
        while(d[i]--) 
            t += s-- * i;
    
    printf("%d", t);
}
