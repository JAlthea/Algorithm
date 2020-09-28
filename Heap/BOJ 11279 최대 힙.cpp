#include <queue>
#include <ios>
using namespace std;

int main()
{
    int n, x;
    priority_queue<int> pq;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        if (x)
            pq.push(x);
        else
        {
            if(pq.empty())
            {
                puts("0");
                continue;
            }

            printf("%d\n", pq.top());
            pq.pop();
        }
    }
}
