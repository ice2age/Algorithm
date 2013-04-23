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

const int MAX = 3000;
double c[MAX];
double l, r;
int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> l >> r;
		for (int i = 0; i < n; ++i)
			cin >> c[i];
		double sum = 0;
		double a = 0;
		for (int i = 0; i < n; ++i)
		{
			a += c[i];
			sum += a;
		}
		printf ("%.2lf\n", (n*l+r-2*sum)/(n+1));
		if (t)
			cout << endl;
	}
	return 0;
}