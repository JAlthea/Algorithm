/*
#import <ios>
int a, b, s;
int main()
{
    while (~scanf("%d%d", &a, &b))
        if (b > a) s += b - a;
    printf("%d", s);
}
*/
/*
위 AC코드에 대한 반례
0 1
1 0
0 13
13 0
output : 14, answer : 13
*/

#import <ios>
int a, b, d[4], i, s, t;
int main()
{
    while (~scanf("%d%d", &a, &b))
    {
        d[i] = b - a + t;
        t = d[i++];
        if (s < t) s = t;
    }
    printf("%d", s);
}
