#include <cstdio>
#include <cassert>
#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		if (start == end)
			return 1;
		dict.insert(end);
		int n = start.size();
		queue<pair<string, int>> que;
		que.push(make_pair(start, 1));
		dict.erase(start);
		while (!que.empty())
		{
			auto top = que.front();
			que.pop();

			for (int i = 0; i < n; ++i)
			{
				string temp = top.first;
				for (char c = 'a'; c <= 'z'; ++c)
				{
					temp[i] = c;
					if (dict.count(temp))
					{
						if (temp == end)
							return top.second+1;
						que.push(make_pair(temp, top.second+1));
						dict.erase(temp);
					}
				}
			}
		}
		return 0;
	}
};

int main()
{
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	Solution s;
	cout << s.ladderLength(start, end, dict) << endl;

	return 0;
}