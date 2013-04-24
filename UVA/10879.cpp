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
	int n, m, c;
	cin >> n;
	for (int t = 1; t <= n; ++t)
	{
		cin >> m;
		printf ("Case #%d: %d", t, m);
		c = 0;
		for (int a = 2; a < m; ++a)
		{
			int b = m / a;
			if (a*b == m)
			{
				++c;
				printf (" = %d * %d", a, b);
				if (c == 2)
				{
					cout << endl;
					break;
				}
			}
		}
	}
	return 0;
}