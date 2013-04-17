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

const int MAX = 10000;
int c[MAX+1];

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, q, num, t = 0;
	while (cin >> n >> q && n > 0 && q > 0)
	{
		memset(c, 0, sizeof(c));
		while (n--)
		{
			cin >> num;
			++c[num];
		}
		for (int i = 1; i <= MAX; ++i)
			c[i] += c[i-1];

		printf ("CASE# %d:\n", ++t);
		while (q--)
		{
			cin >> num;
			int diff = c[num];
			int pre = 0;
			if (num > 0)
			{
				diff -= c[num-1];
				pre = c[num-1];
			}
			if (diff > 0)
				printf ("%d found at %d\n", num, pre+1);
			else
				printf ("%d not found\n", num);
		}
	}
	return 0;
}