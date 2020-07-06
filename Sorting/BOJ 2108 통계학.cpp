#import <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t, d[8001] = { 0 }, c[8001] = { 0 };
	vector<int> v;
	double avr = 0;
	int med = 0;
	int mul = 0;
	int size = 0;
    
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &t);
		avr += t;
		d[t + 4000]++;
		c[t + 4000]++;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	sort(c, c + 8001);
	int max = c[8000];
	int duf = 0;
	for (int i = 7999; i >= 0; i--)
	{
		if (max == c[i])
		{
			duf++;
			break;
		}
	}
	for (int i = 0; i < 8001; i++)
	{
		if (d[i] == max)
		{
			if (duf == 0)
			{
				mul = i - 4000;
				break;
			}
			else
				duf--;
		}
	}

	avr = round((double)avr / (double)v.size());
	med = v[(v.size() - 1) / 2];
	size = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());

	printf("%d %d %d %d\n", (int)avr, med, mul, size);
}
