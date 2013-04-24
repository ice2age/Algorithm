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
	Loong n;
	while (cin >> n && n > 0)
	{
		Loong k = 2;
		Loong q = Loong(sqrt(n) + 0.5);
		while (n > 1 && k <= q)
		{
			while (n % k == 0)
			{
				cout << "    " << k << endl;
				n /= k;
			}
			++k;
			q = Loong(sqrt(n) + 0.5);
		}
		if (n != 1)
			cout << "    " << n << endl;
		cout << endl;
	}
	return 0;
}