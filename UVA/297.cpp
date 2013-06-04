#include <iostream>
#include <cstring>
#include <cstdio>
#include <utility>
#include <cassert>

using namespace std;

const int SIZE = 32;
char limg[SIZE][SIZE];
char rimg[SIZE][SIZE];

struct Pt
{
	Pt(int x, int y): x(x), y(y){}
	int x, y;

	Pt operator + (const Pt& rhs) const
	{
		return Pt(x+rhs.x, y+rhs.y);
	}

	Pt operator / (int s)
	{
		Pt t(*this);
		t.x /= s;
		t.y /= s;
		return t;
	}
};

void fill(char* img, char ch, Pt l, Pt r)
{
	int col = r.x - l.x;
	for (int i = l.y; i < r.y; ++i)
		memset(img+i*SIZE+l.x, ch, col);
}

void print(char* img)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			putchar(img[i+j*SIZE]);
		}
		puts("");
	}
}

void parse(char* img, Pt l, Pt r)
{
	char ch = getchar();
	if (ch == '\n')
		return;
	else if (ch == 'e')
		fill(img, 0, l, r);
	else if (ch == 'f')
		fill(img, 1, l, r);
	else
	{
		assert (ch == 'p');
		Pt m = (l + r) / 2;
		parse(img, Pt(m.x, l.y), Pt(r.x, m.y));
		parse(img, l, m);
		parse(img, Pt(l.x, m.y), Pt(m.x, r.y));
		parse(img, m, r);
	}
}

int solve()
{
	int cnt = 0;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			if (limg[i][j] || rimg[i][j])
				++cnt;
	return cnt;
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
		Pt l(0, 0), r(SIZE, SIZE);
		memset(limg, 0, sizeof(limg));
		memset(rimg, 0, sizeof(rimg));
		parse(&limg[0][0], l, r); getchar();
		parse(&rimg[0][0], l, r); getchar();
		printf ("There are %d black pixels.\n", solve());
	}

	return 0;
}