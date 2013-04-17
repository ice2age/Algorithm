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
using namespace std;

typedef long long Loong;

const int MAX = 50;
int c[MAX];
int t[MAX];
int mergeUp(int l, int m, int r)
{
	int inv = 0;
	memcpy(t+l, c+l, (r-l+1)*sizeof(int));
	int i = l, j = m+1, k = l;
	while (i <= m && j <= r)
	{
		if (t[i] <= t[j])
			c[k++] = t[i++];
		else
		{
			c[k++] = t[j++];
			inv += (m - i + 1);
		}
	}
	while (i <= m)
		c[k++] = t[i++];
	while (j <= r)
		c[k++] = t[j++];
	return inv;
}

int countInversion(int l, int r)
{
	int inv = 0;
	if (l < r)
	{
		int m = (l + r) >> 1;
		inv += countInversion(l, m);
		inv += countInversion(m+1, r);
		inv += mergeUp(l, m, r);
	}
	return inv;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> c[i];

		printf ("Optimal train swapping takes %d swaps.\n", countInversion(0, n-1));
	}
	return 0;
}