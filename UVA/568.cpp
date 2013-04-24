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
	int n, ans;
	while (cin >> n)
	{
		for (int i = ans = 1; i <= n; ++i)
		{
			ans = ans * i;
			while (ans && ans % 10 == 0)
				ans /= 10;
			if (ans) ans %= 100000;
		}
		printf ("%5d -> %d\n", n, ans % 10);
	}
	return 0;
}