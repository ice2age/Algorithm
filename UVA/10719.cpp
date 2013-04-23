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

int aa[10000];
int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int k, n, a, b;
	string line;
	while (cin >> k)
	{
		getchar();
		getline(cin, line);
		istringstream in(line);
		n = 0;
		while (in >> a)
			aa[n++] = a;
		cout << "q(x): ";
		for (int i = b = 0; i < n-1; ++i)
		{
			b = k*b + aa[i];
			cout << b << (i == n-2 ? '\n' : ' ');
		}
		cout << "r = " << k*b+aa[n-1] << endl << endl;
	}

	return 0;
}