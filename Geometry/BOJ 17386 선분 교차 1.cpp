#include <bits/stdc++.h>
using namespace std;

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long ret = x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1);
	if (ret > 0) return 1;
	if (ret < 0) return -1;
	return 0;
}

bool isContainLine(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	if (x1 <= x3 && x3 <= x2 && y1 <= y3 && y3 <= y2)
		return true;
	if (x1 <= x3 && x3 <= x2 && y1 >= y3 && y3 >= y2)
		return true;
	if (x1 >= x3 && x3 >= x2 && y1 <= y3 && y3 <= y2)
		return true;
	if (x1 >= x3 && x3 >= x2 && y1 >= y3 && y3 >= y2)
		return true;

	return false;
}

int main() {
	long long x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	long long r1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	long long r2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	
	int ret = 0;
	if (r1 == 0 || r2 == 0) {
		if (ccw(x1, y1, x2, y2, x3, y3) == 0) {
			if (isContainLine(x1, y1, x2, y2, x3, y3))
			    ret = 1;
		}
		else if (ccw(x1, y1, x2, y2, x4, y4) == 0) {
			if (isContainLine(x1, y1, x2, y2, x4, y4))
				ret = 1;
		}
		else if (ccw(x3, y3, x4, y4, x1, y1) == 0) {
			if (isContainLine(x3, y3, x4, y4, x1, y1))
				ret = 1;
		}
		else if (ccw(x3, y3, x4, y4, x2, y2) == 0) {
			if (isContainLine(x3, y3, x4, y4, x2, y2))
				ret = 1;
		}
	}
	else if (r1 == -1 && r2 == -1) {
		ret = 1;
	}

	cout << ret;
}
