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
	int n;
	while (cin >> n && n > 0)
	{
		int k = ceil(sqrt(n));
		n = n - (k-1)*(k-1);

		if (k & 1)
		{
			if (n <= k)
				cout << k << " " << n << endl;
			else
				cout << 2*k-n << " " << k << endl;
		}
		else
		{
			if (n <= k)
				cout << n << " " << k << endl;
			else
				cout << k  << " " << 2*k-n << endl;
		}
	}
	return 0;
}