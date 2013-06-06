#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

const int SIZE = 80;
int col[2*SIZE+1], l, r;

bool solve(int c)
{
	int v;
	cin >> v;
	if (v == -1)
	{
		if (c == SIZE)
			return false;
		return true;
	}
	
	col[c] += v;
	if (c < l)
		l = c;
	if (c > r)
		r = c;

	solve(c-1);
	solve(c+1);
	return true;
}

void print(int t)
{
	cout << "Case " << t << ":" << endl;
	for (int i = l; i < r; ++i)
		cout << col[i] << " ";
	cout << col[r] << endl << endl;;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t = 0;
	while (++t)
	{
		l = r = SIZE;
		memset(col, 0, sizeof(col));
		if (!solve(l))
			break;
		print(t);
	}

	return 0;
}