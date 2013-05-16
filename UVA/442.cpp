#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cmath>
#include <utility>

using namespace std;
typedef long long Loong;

typedef pair<int, int> matrix;
matrix all[26];

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	char ch;
	int n, w, h;
	cin >> n;
	while (n--)
	{
		cin >> ch >> w >> h;
		all[ch-'A'] = make_pair(w, h);
	}

	while (true)
	{
		int sum = 0;
		bool error = false;
		stack<matrix> stk;
		char line[100];
		if (scanf ("%s", line) == EOF)
			break;
		for (int i = 0; line[i]; ++i)
		{
			ch = line[i];
			if (ch >= 'A' && ch <= 'Z')
			{
				stk.push(all[ch-'A']);
			}
			else if (ch == ')')
			{
				if (stk.size() < 2)
				{
					error = true;
					break;
				}
				matrix mb = stk.top(); stk.pop();
				matrix ma = stk.top(); stk.pop();
				if (ma.second != mb.first)
				{
					error = true;
					break;
				}
				sum += ma.first * mb.first * mb.second;
				stk.push(make_pair(ma.first, mb.second));
			}
		}
		if (error)
			cout << "error" << endl;
		else
			cout << sum << endl;
		if (ch == EOF)
			break;
	}

	return 0;
}