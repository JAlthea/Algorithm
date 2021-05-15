#include <queue>
#include <ios>
using namespace std;

int main()
{
    int n, k, i, t;
    queue<int> q;
    scanf("%d%d", &n, &k);
    for(i=1; i<=n; ++i)
        q.push(i);
    i = 1;
    printf("<");
    while(!q.empty())
    {
        t = q.front();
        if(i != k)
        {
            q.pop();
            q.push(t);
            i++;
        }
        else
        {
            q.pop();
            if(q.empty())
                printf("%d", t);
            else
                printf("%d, ", t);
            i = 1;
        }
    }
    printf(">");
}
