#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(string dirs) {
	int answer = 0;
	set<vector<int>> s;
	vector<int> a(4), b(4);
	int x = 0, y = 0;
	for (int i = 0; i < dirs.size(); ++i) {
		a[0] = x; b[2] = x;
		a[1] = y; b[3] = y;

		if (dirs[i] == 'L' && x > -5) --x;
		else if (dirs[i] == 'U' && y < 5) ++y;
		else if (dirs[i] == 'R' && x < 5) ++x;
		else if (dirs[i] == 'D' && y > -5) --y;
		else continue;

		a[2] = x; b[0] = x;
		a[3] = y; b[1] = y;
		if (s.find(a) == s.end() && s.find(b) == s.end()) s.insert(a);
		else continue;
	}

	return answer = s.size();
}
