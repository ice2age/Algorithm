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
	int a;
	while (cin >> a && a > 0)
	{
		a = 4 << ((a - 1960) / 10);
		int n = 1;
		double t = a * log(2);
		double s = 0;
		while (s < t)
		{
			s += log(n++);
		}
		cout << n - 2 << endl;
	}
	return 0;
}