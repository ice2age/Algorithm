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

struct Card
{
	Card(){}
	Card(char a, char b):a(a), b(b){}
	char a, b;
	char& operator[](int i)
	{
		return (&a)[i];
	}
	bool operator == (const Card& rhs)
	{
		return a == rhs.a || b == rhs.b;
	}
};

int off[2] = {3, 1};
const int MAX_N = 52;
int n, cnt[MAX_N];
Card cards[MAX_N][MAX_N];

bool check(int j, int i)
{
	if (j < 0 || j >= n)
		return false;
	if (i < 0 || i >= n)
		return false;
	if (!cnt[i] || !cnt[j])
		return false;
	if (cards[i][cnt[i]-1] == cards[j][cnt[j]-1])
		return true;
	return false;
}

bool compress(int i);
void moveone(int j, int i)
{
	cards[j][cnt[j]++] = cards[i][--cnt[i]];
	if (!cnt[i])
	{
		for (int k = i+1; k < n; ++k)
			if (cnt[k] > 0)
			{
				memcpy(cards[k-1], cards[k], cnt[k]*sizeof(Card));
				cnt[k-1] = cnt[k];
				cnt[k] = 0;
			}
		--n;
	}
	for (; j < n; ++j)
		if (compress(j))
			break;
}

bool compress(int i)
{
	for (int k = 0; k < sizeof(off)/sizeof(off[0]); ++k)
	{
		if (check(i-3, i))
		{
			moveone(i-3, i);
			return true;
		}
		if (check(i-1, i))
		{
			moveone(i-1, i);
			return true;
		}
	}
	return false;
}

void input(const string& line)
{
	string card;
	istringstream in(line);
	
	while (in >> card)
	{
		
		cards[n][0] = Card(card[0], card[1]);
		cnt[n]++;
		n++;
		compress(n-1);
	}
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	string line;
	while (getline(cin, line))
	{
		if (line == "#")
			break;
		n = 0;
		memset(cnt, 0, sizeof(cnt));
		input(line);
		getline(cin, line);
		input(line);
		printf ("%d pile%s remaining:", n, n==1?"":"s");
		for (int i = 0; i < n; ++i)
			printf(" %d", cnt[i]);
		puts("");
	}
	return 0;
}