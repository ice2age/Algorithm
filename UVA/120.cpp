#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cmath>
#include <utility>
using namespace std;

typedef long long Loong;

int n;
int c[100];

void flip(int k)
{
	if (k == n-1)
		return;
	for (int i = k, j = n-1; i < j; ++i, --j)
		swap(c[i], c[j]);
	cout << k+1 << " ";
}
int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	string line;
	while (getline(cin, line))
	{
		cout << line << endl;
		istringstream in(line);
		int d;
		n = 0;
		while (in >> d)
			c[n++] = d;
		for (int i = 0, j = n-1; i < j; ++i, --j)
			swap(c[i], c[j]);

		for (int i = 0; i < n; ++i)
		{
			int mx = i;
			for (int j = i+1; j < n; ++j)
				if (c[j] > c[mx])
					mx = j;
			if (i != mx)
			{
				flip(mx);
				flip(i);
			}
		}
		cout << 0 << endl;
	}
	return 0;
}