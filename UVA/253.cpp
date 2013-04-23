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
int r[][6] = {{0,1,2,3,4,5},{1,5,2,3,0,4},{2,1,5,0,4,3},{3,1,0,5,4,2},{4,0,2,3,5,1},{5,4,2,3,1,0}};

int match(char* a, char* b)
{
	char c[7];
	memset(c, 0, sizeof(c));
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
			c[j] = b[r[i][j]];
		for (int k = 0; k < 4; ++k)
		{
			char t = c[1];
			c[1] = c[2];
			c[2] = c[4];
			c[4] = c[3];
			c[3] = t;
			if (strcmp(a, c) == 0)
				return 1;
		}
	}
	return 0;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	char a[13];
	char b[7];
	char* ans[] = {"FALSE", "TRUE"};
	while (cin >> a)
	{
		for (int i = 0; i < 6; ++i)
			b[i] = a[i+6];
		a[6] = b[6] = 0;
		puts(ans[match(a,b)]);
	}
	return 0;
}