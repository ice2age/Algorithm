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

int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t; 
	}
	return a;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int s, m;
	char* ans[] = {"Bad Choice", "Good Choice"};
	while (cin >> s >> m)
	{
		int g = gcd(s, m);
		printf ("%10d%10d    %s\n\n", s, m, ans[g==1]);
	}
	return 0;
}