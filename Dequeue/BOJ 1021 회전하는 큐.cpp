#include <bits/stdc++.h>
using namespace std;

int findIndex(deque<int> &d, int n) {
    int index = 0;
    for (deque<int>::iterator iter = d.begin(); iter != d.end(); ++iter, ++index)     
        if (*iter == n)
            break;
    
    return index;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<int> v(m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &v[i]); 
    
    deque<int> d;
    for (int i = 1; i <= n; +i)
        d.push_back(i);
    
        
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int index = findIndex(d, v[i]);
        bool reverse = false;
        
        if (index > d.size() - index) {
            index = d.size() - index;
            reverse = true;
        }
        
        sum += index;
        while (index--) {
            if (reverse) {
                d.push_front(d.back());
                d.pop_back();
            }
            else {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        
        if (d.front() == v[i])
            d.pop_front();
    }
    
    printf("%d", sum);
}
