#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cmath>
#include <utility>

using namespace std;

typedef long long Loong;

struct Key
{
	Key(string k, int t, int w) : key(k), tID(t), wID(w) {}
	string key;
	int tID;
	int wID;
};

bool operator < (const Key& lhs, const Key& rhs)
{
	if (lhs.key != rhs.key)
		return lhs.key < rhs.key;
	if (lhs.tID != rhs.tID)
		return lhs.tID < rhs.tID;
	return lhs.wID < rhs.wID;
}

vector<string> titles[200];

inline void tolowercase(string& str)
{
	int l = str.length();
	for (int i = 0; i < l; ++i)
		str[i] = tolower(str[i]);
}

inline void touppercase(string& str)
{
	int l = str.length();
	for (int i = 0; i < l; ++i)
		str[i] = toupper(str[i]);
}


int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tID, wID;
	string line;
	set<string>ignore;
	while (getline(cin, line))
	{
		if (line == "::")
			break;
		ignore.insert(line);
	}

	vector<Key> keys;
	tID = 0;
	while (getline(cin, line))
	{
		wID = 0;
		string word;
		istringstream in(line);
		while (in >> word)
		{
			tolowercase(word);
			if (!ignore.count(word))
			{
				keys.push_back(Key(word, tID, wID));
			}
			wID++;
			titles[tID].push_back(word);
		}
		tID++;
	}

	sort(keys.begin(), keys.end());

	for (size_t i = 0; i < keys.size(); ++i)
	{
		const Key& k = keys[i];
		vector<string>& title = titles[k.tID];
		int tsz = title.size();
		for (int j = 0; j < tsz; ++j)
		{
			string word = title[j];
			if (j == k.wID)
				touppercase(word);
			cout << word;
			if (j == tsz-1)
				cout << endl;
			else
				cout << " ";
		}
	}
	return 0;
}