#include <queue>
#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    deque<int> d;
    
    while (n--) {
        string tmp;
        int m;
        cin >> tmp;
        
        if (tmp == "push_back") {
            cin >> m;
            d.push_back(m);
        }
        else if (tmp == "push_front") {
            cin >> m;
            d.push_front(m);
        }
        else if (tmp == "front") {
            if (d.empty()) {
                cout << "-1" << '\n';
                continue;
            }
            cout << d.front() << '\n';
        }
        else if (tmp == "back") {
            if (d.empty()) {
                cout << "-1" << '\n';
                continue;
            }
            cout << d.back() << '\n';
        }
        else if (tmp == "size")
            cout << d.size() << '\n';
        else if (tmp == "empty")
            cout << d.empty() << '\n';
        else if (tmp == "pop_back") {
            if (d.empty()) {
                cout << "-1" << '\n';
                continue;
            }
            cout << d.back() << '\n';
            d.pop_back();
        }
        else if (tmp == "pop_front" ){
            if (d.empty()) {
                cout << "-1" << '\n';
                continue;
            }
            cout << d.front() << '\n';
            d.pop_front();
        }
    }
}
