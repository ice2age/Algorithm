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
	char line[100];
	while (cin >> line)
	{
		if (strcmp(line, "0") == 0)
			break;
		int l = strlen(line);
		Loong b = 2, s = 0;
		for (int i = l-1; i >= 0; --i, b <<= 1)
			s += (line[i] - '0') * (b - 1);
		cout << s << endl;
	}
	return 0;
}