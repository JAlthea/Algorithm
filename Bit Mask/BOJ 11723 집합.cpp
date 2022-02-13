#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int m, x, s = 0;
	cin >> m;
	
	while (m--) {
		string c;
		cin >> c;
        
		if (c == "all") 
            s = (1 << 21) - 1;
		else if (c == "empty") 
            s = 0;
		else 
            cin >> x;
        
		if (c == "add") 
            s |= (1 << x);
		else if (c == "check") 
            cout << ((s & (1 << x)) ? "1\n" : "0\n");
		else if (c == "remove") 
            s &= ~(1 << x);
		else if (c == "toggle") 
            s ^= (1 << x);
	}
}
