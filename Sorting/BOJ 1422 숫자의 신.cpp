#include <bits/stdc++.h>
using namespace std;

int main() {
	  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	  int k, n;
	  cin >> k >> n;
	  vector<int> arr(k);
	  for (int i = 0; i < k; ++i)
	  	  cin >> arr[i];

	  int maxNumber = *max_element(arr.begin(), arr.end());
	  bool flag = true;
	  sort(arr.begin(), arr.end(), [](int & a, int & b) { 
	  	  return to_string(a) + to_string(b) > to_string(b) + to_string(a); 
	  });
    
	  for (int i = 0; i < k; ++i) {
	  	  if (flag && maxNumber == arr[i]) {
	  	  	  for (int j = 0; j < n - k; ++j)
	  	  	  	  cout << maxNumber;
            
	  	  	  flag = false;
	  	  }
        
	  	  cout << arr[i];
	  }
}
