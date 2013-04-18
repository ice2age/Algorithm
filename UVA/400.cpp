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

const int MAX = 60;
char file[100][MAX+1];

int cmp(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}

void pad(int n)
{
	while (n--)
		putchar(' ');
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, l, mx;
	while (cin >> n)
	{
		for (int i = 0; i < MAX; ++i)
			putchar('-');
		putchar('\n');
		mx = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> file[i];
			l = strlen(file[i]);
			if (l > mx) mx = l;
		}
		qsort(file, n, sizeof(file[0]), cmp);
		int col = (MAX - mx) / (mx + 2) + 1;
		int row = (n + col - 1) / col;
		//cout << row << " " << col << endl;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				int id = j * row + i;
				if (id >= n)
					break;
				cout << file[id];
				l = strlen(file[id]);
				if (j == col-1)
					pad(mx-l);
				else
					pad(mx+2-l);
			}
			putchar('\n');
		}
	}
	return 0;
}