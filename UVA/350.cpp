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

const int MAX = 10000;
int c[MAX];

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int z, i, m, l, t = 0;
	while (cin >> z >> i >> m >> l)
	{
		if (z == 0 && i == 0 && m == 0 && l == 0)
			break;
		memset(c, 0, sizeof(c));

		int cnt = 1;
		c[l] = cnt;
		while(true)
		{
			l = (z*l+i) % m;
			if (c[l] != 0)
				break;
			c[l] = ++cnt;
		}
		cout << "Case " << ++t << ": " << cnt - c[l] + 1 << endl;
	}
	return 0;
}