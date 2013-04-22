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
	Loong m, n;
	int t = 0;
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)
			break;
		cout << "Case "<< ++t <<": ";
		cout << ((m*(m-1))>>1)*((n*(n-1))>>1) << endl;
	}

	return 0;
}