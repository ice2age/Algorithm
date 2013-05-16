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

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	char line[130];
	cin >> n;
	getchar();
	while (n--)
	{
		gets(line);
		stack<char> s;
		bool yes = true;
		for (int i = 0; line[i]; ++i)
		{
			if (line[i] == '(' || line[i] == '[')
				s.push(line[i]);

			else if (s.empty())
			{
				yes = false;
				break;
			}
			else if ((line[i] == ')' && s.top() == '(') || (line[i] == ']' && s.top() == '['))
			{
				s.pop();
			}
			else
			{
				yes = false;
				break;
			}
		}
		if (yes && s.empty())
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}