#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cmath>
#include <utility>

using namespace std;

typedef long long Loong;


int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int h, u, d;
	double f;
	while (cin >> h >> u >> d >> f && h > 0)
	{
		f *= 0.01;
		int day = 0;
		double dis = 0.0;
		while (true)
		{
			dis += max(0.0, u*(1.0-day*f));
			day++;
			if (dis > h)
			{
				printf ("success on day %d\n", day);
				break;
			}
			dis -= d;
			if (dis < 0)
			{
				printf ("failure on day %d\n", day);
				break;
			}
		}
	}
	return 0;
}