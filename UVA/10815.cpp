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
	string line, word;
	set<string> dic;
	while (getline(cin, line))
	{
		for (int i = 0; line[i]; ++i)
			if (isalpha(line[i]))
				line[i] = tolower(line[i]);
			else
				line[i] = ' ';

		istringstream in(line);
		while (in >> word)
			dic.insert(word);	
	}
	for (set<string>::const_iterator it = dic.begin();
		it != dic.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
