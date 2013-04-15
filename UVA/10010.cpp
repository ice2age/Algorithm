#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

typedef long long Loong;

int m, n;
char grid[50][51];
char word[100];
int dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

bool searchWord(int r, int c, int length, int step[2])
{
	for (int l = 0; l < length; ++l, r+=step[0],c+=step[1])
	{
		if (r < 0 || r >= m)
			return false;
		if (c < 0 || c >= n)
			return false;
		if (tolower(grid[r][c]) != tolower(word[l]))
			return false;
	}
	return true;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int T, k;
	cin >> T;
	while (T--)
	{
		cin >> m >> n;
		for (int i = 0; i < m; ++i)
			cin >> grid[i];
		cin >> k;
		while (k--)
		{
			cin >> word;
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					for (int d = 0; d < 8; ++d)
					{
						if (searchWord(i, j, strlen(word), dir[d]))
						{
							printf ("%d %d\n", i+1, j+1);
							goto next;
						}
					}
				}
			}
next:
			;
		}

		if (T)
			puts("");
	}

	return 0;
}
