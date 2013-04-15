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


int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	char line[20];
	while (gets(line))
	{
		if (line[0] == '|')
		{
			int ch = 0;
			int offset = 7;
			for (int i = 1; line[i]; ++i)
			{
				if (line[i] == 'o')
					ch += 1 << offset;
				if (line[i] == ' ' || line[i] == 'o')
					--offset;
			}
			printf ("%c", ch);
		}
	}
	return 0;
}
