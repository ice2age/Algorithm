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

int counts[20];
char excuses[20][71];

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int k, e, t=0;
	string key, word;
	while (cin >> k >> e)
	{
		map<string, int> keys;

		while (k--)
		{
			cin >> key;
			++keys[key];
		}
		getchar();

		int mx = 0;
		for (int i = 0; i < e; ++i)
		{
			gets(excuses[i]);
			string excu = excuses[i];
			for (int j = 0; excu[j]; ++j)
			{
				if (isalpha(excu[j]))
					excu[j] = tolower(excu[j]);
				else if (!isdigit(excu[j]))
					excu[j] = ' ';
			}
			int cnt = 0;
			istringstream in(excu);
			while (in >> word)
				if (keys.count(word))
					cnt += keys[word];

			counts[i] = cnt;
			if (cnt > mx)
				mx = cnt;
		}

		printf ("Excuse Set #%d\n", ++t);
		for (int i = 0; i < e; ++i)
			if (counts[i] == mx)
				cout << excuses[i] << endl;
		cout << endl;
	}
	return 0;
}
