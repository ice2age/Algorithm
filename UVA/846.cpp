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
	//freopen("input.txt", "r", stdin);
#endif
	int t, x, y, n;
	cin >> t;
	while(t--)
	{
		cin >> x >> y;
		y -= x;
		if (y == 0)
		{
			cout << 0 << endl;
			continue;
		}
		n = (int)floor(sqrt(y+0.5));
		//n = (int)sqrt(y); both ok
		if (y == n*n)
			cout << 2*n - 1 << endl;
		else if (y <= n*n+n)
			cout << 2*n << endl;
		else
			cout << 2*n+1 << endl;
	}

	return 0;
}