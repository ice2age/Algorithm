#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cmath>
using namespace std;

typedef long long Loong;

int tree[5000][3];
int cnt[10];

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int x, y, z;
	int n = 0;
	while (cin >> tree[n][0] >> tree[n][1] >> tree[n][2])
	{
		if (!tree[n][0] && !tree[n][1] && !tree[n][2])
			break;
		++n;
	}

	for (int i = 0; i < n; ++i)
	{
		int min = 5000;
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue;
			x = tree[j][0] - tree[i][0];
			y = tree[j][1] - tree[i][1];
			z = tree[j][2] - tree[i][2];
			int d = x*x + y*y + z*z;
			if (d < min)
				min = d;
		}
		min = sqrt(min);
		if (min >= 10) continue;
		cnt[min]+=1;
	}

	for (int i = 0; i < 10; ++i)
		printf ("%4d", cnt[i]);
	puts("");
	return 0;
}