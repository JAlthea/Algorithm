#import <ios>
#import <stack>

int main()
{
    std::stack<int> s;
    int k, n;
    scanf("%d", &k);
    while(k--)
    {
        scanf("%d", &n);
        n ? s.push(n) : s.pop();
    }
    n = 0;
    while(!s.empty())
    {
        n += s.top();
        s.pop();
    }
    printf("%d", n);
}
