#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    map<string, int> enterLogs, leaveLogs;
    set<string> names;
    vector<string> workers;
    
    string inputName, inputType;
    for (int i = 0; i < n; ++i) {
        cin >> inputName >> inputType;
        names.insert(inputName);
        if (inputType == "enter") {
            enterLogs[inputName]++;
        }
        else {
            leaveLogs[inputName]++;
        }
    }
    
    for (auto & name : names) {
        if (enterLogs[name] - leaveLogs[name] > 0) {
            workers.push_back(name);
        }
    }
    
    sort(workers.begin(), workers.end(), greater<string>());
    for (auto & worker : workers) {
        cout << worker << '\n';
    }
}
