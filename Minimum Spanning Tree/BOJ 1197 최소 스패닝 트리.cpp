#include <ios>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

int findSet(vector<int> &d, int node) {
    if (node == d[node])
        return node;
    return d[node] = findSet(d, d[node]);
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), cmp);
    
    vector<int> d(10001, 0);
    for (int i=0; i<n; i++)
        d[i] = i;

    int answer = 0;
    for (int i=0; i<costs.size(); i++)
    {
        int start = findSet(d, costs[i][0]);
        int end = findSet(d, costs[i][1]);
        if (start != end)
        {
            d[start] = end;
            answer += costs[i][2];
        }
    }
    return answer;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> edges;
    while(m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({a, b, c});
    }
    printf("%d", solution(n, edges));
}
