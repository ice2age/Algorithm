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

int s[1000];
int cs[10];
int cg[10];
int c[10];

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, g, sum, t = 0;
	while (cin >> n && n)
	{
		cout << "Game " << ++t << ":" << endl;
		memset(cs, 0, sizeof(cs));
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
			++cs[s[i]];
		}
		while (true)
		{
			sum = 0;
			int a = 0, b = 0;
			memcpy(c, cs, sizeof(cs));
			memset(cg, 0, sizeof(cg));
			for (int i = 0; i < n; ++i)
			{
				cin >> g;
				sum += g;
				if (s[i] == g)
				{
					++a;
					--c[g];
				}
				else
					++cg[g];
			}
			if (sum == 0)
				break;
			for (int i = 1; i < 10; ++i)
				b += min(c[i], cg[i]);
			printf ("    (%d,%d)\n", a, b);
		}

	}
	return 0;
}