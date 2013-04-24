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

inline int odd(size_t n)
{
	size_t q = (size_t)floor(sqrt(n) + 0.5);
	if (q * q == n)
		return 1;
	return 0;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	size_t n;
	char* ans[] = {"no", "yes"};
	while (cin >> n && n > 0)
		puts(ans[odd(n)]);
	return 0;
}