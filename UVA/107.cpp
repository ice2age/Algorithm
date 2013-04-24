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
	int h, w, nw, sh;
	while (cin >> h >> w)
	{
		if (h == 0 && w == 0)
			break;

		if (h == 1 && w == 1)
		{
			puts("0 1");
			continue;
		}

		int k = 1;
		while (int(pow(pow(w, 1.0/k) + 1, k) + 0.5) != h)
			++k;
		int N = (int)floor(pow(w, 1.0/k)+0.5);
		nw = sh = 0;
		for (int i = 0, n = 1; i < k; ++i, n*=N, h/=(N+1))
		{
			nw += n;
			sh += n*h;
		}
		sh += w;
		cout << nw << " " << sh << endl;
	}
	return 0;
}