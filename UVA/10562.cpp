#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

const int SIZE = 200;
char tree[SIZE][SIZE+1];
int row;

bool printable(char ch)
{
	if (ch == '-' || ch == '|' || ch ==  ' ' || ch == '#')
		return false;
	return true;
}

void dfs1(int d, int l, int r)
{
	//printf ("level %d, [%d - %d]\n", d, l, r);
	char ch;
	cout << "(";
	for (int i = l; i <= r; ++i)
	{
		ch = tree[d][i];
		if (printable(ch))
		{
			putchar(ch);
			if (d < row-3 && tree[d+1][i] == '|')
			{
				assert (tree[d+2][i] == '-');
				int ll = i, rr = i;
				while (ll>0 && tree[d+2][ll-1] == '-')
					ll--;
				while (tree[d+2][rr+1] == '-')
					rr++;
				dfs1(d+3, ll, rr);
			}
		}
	}
	cout << ")";
}

void dfs(int d, int c)
{
	//printf ("level %d, [%d]\n", d, c);
	if (d > row-1)
	{
		return;
	}
	assert (printable(tree[d][c]));

	putchar(tree[d][c]);
	if (d >= row-1 || tree[d+1][c] != '|')
		cout << "()";
	else if (d < row-3 && tree[d+1][c] == '|')
	{
		cout << "(";
		assert (tree[d+2][c] == '-');
		int ll = c, rr = c;
		while (ll>0 && tree[d+2][ll-1] == '-')
			ll--;
		while (tree[d+2][rr+1] == '-')
			rr++;
		for (int i = ll; i <= rr && tree[d+3][i]; ++i)
			if (printable(tree[d+3][i]))
			{
				dfs(d+3, i);
			}
			cout << ")";
	}
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		row = 0;
		while (gets(tree[row]))
		{
			if (strcmp(tree[row], "#") == 0)
				break;
			++row;
		}
		putchar('(');
		dfs(0, strlen(tree[0])-1);
		puts(")");
	}

	return 0;
}