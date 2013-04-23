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
	int t, k;
	cin >> t;
	while (t--)
	{
		cin >> k;
		if (k < 0)
			k = -k;
		if (k == 0)
		{
			puts("3");
		}
		else
		{
			int n = int(0.5*sqrt(8.0*k+1) - 0.5);
			while (n*(n+1)/2 < k)
				n++;
			while (1)
			{
				if ((n*(n+1)/2 - k) % 2 == 0)
					break;
				n++;
			}
			cout << n << endl;
		}
		if (t) cout << endl;
	}
	return 0;
}