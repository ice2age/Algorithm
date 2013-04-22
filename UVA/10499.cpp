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
	while(cin >> n && n > 0)
	{
		if (n == 1)
			cout << 0 << "%" << endl;
		else
			cout << 25LL*n << "%" << endl;
	}

	return 0;
}