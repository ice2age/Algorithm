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
	int n, s, c, t = 0;
	int h[50];
	while (cin >> n && n > 0)
	{
		s = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> h[i];
			s += h[i];
		}
		s /= n;
		sort(h, h+n);
		c = 0;
		for (int i = n-1; i >= 0 && h[i] > s; --i)
			c += h[i] - s;
		printf ("Set #%d\nThe minimum number of moves is %d.\n\n", ++t, c);
	}
	return 0;
}