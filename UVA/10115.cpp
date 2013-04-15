#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long Loong;


int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	string line, rules[10][2];
	while (cin >> n && n > 0)
	{
		getchar();
		for (int i = 0; i < n; ++i)
		{
			getline(cin, rules[i][0]);
			getline(cin, rules[i][1]);
		}
		getline(cin, line);
		int i = 0;
		while (i < n)
		{
			int pos = line.find(rules[i][0]);
			if (pos != string::npos)
				line.replace(pos, rules[i][0].length(), rules[i][1]);
			else
				i++;
		}
		cout << line << endl;
	}
	return 0;
}
