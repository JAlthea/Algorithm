#import <ios>
int i, d[10]; 
char s[11];
int main()
{
    for (scanf("%s", s); s[i]; i++)
        d[s[i] - 48]++;
    for (i=9; i>=0; i--)
        while (d[i]--)
            printf("%d", i);
}
