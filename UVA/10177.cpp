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
	while(cin >> n)
	{
		Loong a = n*(n+1)*(2*n+1)/6;
		Loong b = n*(n+1)/2;
		Loong c = b*b;
		Loong x = n*n;
		Loong y = x*x;
		Loong d = n*(6*y + 15*x*n + 10*x - 1) / 30;
		cout << a << " " << c-a << " " << c << " " << c*(b-1) << " " << d << " " << c*c - d << endl;
	}

	return 0;
}