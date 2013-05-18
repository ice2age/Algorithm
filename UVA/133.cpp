#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
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
	int n, k, m, flag[20];
	while (cin >> n >> k >> m && n)
	{
		memset(flag, 0, sizeof(flag));
		int i = 0, j = n-1;
		int cnt = n;
		while (cnt > 0)
		{
			int ic = 0; 
			while(true)
			{
				while (flag[i])
					i = (i+1) % n;
				++ic;

				if (ic == k)
					break;
				i = (i+1) % n;
			}
			int jc = 0; 
			while (true)
			{
				while (flag[j])
					j = (j+n-1) % n;
				++jc;

				if (jc == m)
					break;
				j = (j+n-1)%n;
			}
			flag[i] = flag[j] = 1;
			--cnt;
			printf ("%3d", i+1);
			if (i != j)
			{
				--cnt;
				printf ("%3d", j+1);
			}
			if (cnt > 0)
				putchar(',');
		}
		puts("");
	}
	return 0;
}