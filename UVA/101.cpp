#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cmath>
#include <utility>

using namespace std;
typedef long long Loong;

const int MAX_N = 25;
int n, cnt[MAX_N], which[MAX_N], blocks[MAX_N][MAX_N];

void dump()
{
	for (int i = 0; i < n; ++i)
	{
		cout << i << ":";
		for (int j = 0; j < cnt[i]; ++j)
			cout << " " << blocks[i][j];
		cout << endl;
	}
}

void clean(int r, int block)
{
	for (int c = cnt[r]-1; c >= 0; --c)
	{
		int b = blocks[r][c];
		if (b == block)
			break;
		--cnt[r];
		which[b] = b;
		blocks[b][cnt[b]++] = b;
	}
}

void move(int r1, int a, int r2)
{
	blocks[r2][cnt[r2]++] = a;
	--cnt[r1];
	which[a] = r2;
}

void moveonto(int wa, int a, int wb, int b)
{
	clean(wa, a);
	clean(wb, b);
	move(wa, a, wb);
}

void moveover(int wa, int a, int wb, int b)
{
	clean(wa, a);
	move(wa, a, wb);
}

void pile(int wa, int a, int wb)
{
	int i = 0;
	for (; i < cnt[wa] && blocks[wa][i] != a; ++i)
		;
	int temp = i;
	for (; i < cnt[wa]; ++i)
	{
		blocks[wb][cnt[wb]++] = blocks[wa][i];
		which[blocks[wa][i]] = wb;
	}
	cnt[wa] = temp;
}

void pileonto(int wa, int a, int wb, int b)
{
	clean(wb, b);
	pile(wa, a, wb);
}

void pileover(int wa, int a, int wb, int b)
{
	pile(wa, a, wb);
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n;
	getchar();
	for (int i = 0; i < n; ++i)
	{
		cnt[i] = 1;
		which[i] = i;
		blocks[i][0] = i;
	}
	string line;
	while (getline(cin, line))
	{
		if (line == "quit")
			break;
		int a, b;
		string command, act;
		istringstream in(line);
		in >> command >> a >> act >> b;

		if (a == b)
			continue;
		int wa = which[a];
		int wb = which[b];
		if (wa == wb)
			continue;

		if (command == "move")
		{
			if (act == "onto")
				moveonto(wa, a, wb, b);
			else
				moveover(wa, a, wb, b);
		}
		else
		{
			if (act == "onto")
				pileonto(wa, a, wb, b);
			else
				pileover(wa, a, wb, b);
		}
	}
	dump();
	return 0;
}