#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <stack>
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
	int T, n, p, h[100], d[3651];
	cin >> T;
	while (T--)
	{
		cin >> n >> p;
		for (int i = 0; i < p; ++i)
			cin >> h[i];
		memset (d, 0, sizeof(d));
		for (int i = 0; i < p; ++i)
			for (int j = h[i]; j <= n; j += h[i])
				d[j] = 1;
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			if (d[i] && i%7 != 0 && i%7 != 6)
				++sum;
		cout << sum << endl;
	}

	return 0;
}