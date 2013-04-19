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
	int T, a, b;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		cout << (a/3)*(b/3) << endl;//((a-2) + (3-1))/3 = a/3
	}
	return 0;
}