#include <cstdio>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

const int MAX_N = 7;
int order[MAX_N];
char vva[MAX_N+1];
char terminal[(1<<MAX_N)+1];

int main()
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int m, n, T = 0;
	while (cin >> n && n)
	{
		T++;
		getchar();
		for (int i = 0; i < n; ++i)
		{
			scanf ("x%d", &order[i]);
			getchar();
			--order[i];
		}
		int t = 1 << n;
		cin >> terminal;

		printf ("S-Tree #%d:\n", T);
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> vva;
			int cur = 0;
			for (int j = 0; j < n; ++j)
			{
				if (vva[order[j]] == '1')
					cur = 2*(cur+1);
				else
				{
					assert (vva[order[j]] == '0');
					cur = 2*cur+1;
				}
			}
			cur -= (1 << n) - 1;
			assert (cur >= 0 && cur < (1<<n));
			putchar(terminal[cur]);
		}
		cout << endl << endl;
	}
	return 0;
}