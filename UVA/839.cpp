#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

bool solve(int& w)
{
	int w1, d1, w2, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	bool res = true;
	if (w1 == 0)
		res = solve(w1);
	if (w2 == 0)
		res &= solve(w2);
	if (res && d1*w1 != d2*w2)
		res = false;
	w = w1 + w2;
	return res;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, w;
	cin >> n;
	while (n--)
	{
		if (solve(w))
			puts("YES");
		else
			puts("NO");
		if (n)
			puts("");
	}

	return 0;
}