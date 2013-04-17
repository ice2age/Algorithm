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
#include <utility>
using namespace std;

typedef long long Loong;

int cnt[2];
int idx[2];
int lmt[2] = {21, 5};
char l[2][22] = {"AUEOI", "JSBKTCLDMVNWFXGPYHQZR"};
char v[2][105];
int c[2];

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int T, n;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		printf ("Case %d: ", t);
		cin >> n;
		memset(c, 0, sizeof(c));
		memset(cnt, 0, sizeof(cnt));
		memset(idx, 0, sizeof(idx));
		int k = 0, id = 0;
		for (int i = 0; i < n; ++i)
		{
			v[id][c[id]++] = l[id][idx[id]];
			cnt[id]++;
			if (cnt[id] >= lmt[id])
			{
				cnt[id] = 0;
				++idx[id];
			}
			id = 1 - id;
		}
		sort(v[0], v[0]+c[0]);
		sort(v[1], v[1]+c[1]);
		id = 0;
		for (int i = 0; i < n; ++i, id = 1 - id)
			putchar(v[id][i/2]);
		cout << endl;
	}
	return 0;
}