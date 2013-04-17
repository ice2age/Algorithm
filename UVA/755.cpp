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
#include <limits>
using namespace std;

typedef long long Loong;


int mp[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

string standardize(string phone)
{
	string res;
	int cnt = 0;
	for (int i = 0; phone[i]; ++i)
	{
		if (phone[i] == '-')
			continue;
		else if (isalpha(phone[i]))
			res += mp[phone[i]-'A'] + '0';
		else if (isdigit(phone[i]))
			res += phone[i];
		++cnt;
		if (cnt == 3)
			res += "-";
	}
	return res;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int T, n;
	string phone;
	cin >> T;
	while (T--)
	{
		map<string, int> phonebook;
		cin >> n;
		while (n--)
		{
			cin >> phone;
			++phonebook[standardize(phone)];
		}
		int cnt = 0;
		for (map<string,int>::const_iterator it = phonebook.begin();
			it != phonebook.end(); ++it)
		{
			if (it->second > 1)
			{
				cout << it->first << " " << it->second << endl;
				++cnt;
			}
		}
		if (cnt == 0)
			cout << "No duplicates." << endl;
		if (T)
			cout << endl;
	}
	return 0;
}