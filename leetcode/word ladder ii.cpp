#include <cstdio>
#include <cassert>
#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	struct Node{
		Node(string v, int d) : value(v), depth(d) {}
		string value;
		int depth;
	};
	
	void getpath(map<string, string>& parent, vector<string>& v, string start, string end) {
		if (parent[end] != start) {
			getpath(parent, v, start, parent[end]);
			v.push_back(end);
		}
	}
	
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string> > vv;
		if (start == end){
			vector<string> v;
			v.push_back(start);
			vv.push_back(v);
		}
		
		dict.insert(end);
		int n = start.size();
		queue<Node> que;
		map<string, string> parent;
		que.push(Node(start, 1));
		parent[start] = "";
		dict.erase(start);
		int depth = 0;
		while (!que.empty())
		{
			auto top = que.front();
			que.pop();

			for (int i = 0; i < n; ++i)
			{
				for (char c = 'a'; c <= 'z'; ++c)
				{
					string temp = top.value;
					temp[i] = c;
					if (dict.count(temp))
					{
						if (temp == end) {
							if (depth == 0 || top.depth == depth) {
								vector<string> v;
								getpath(parent, v, start, end);
								vv.push_back(v);
								depth = top.depth;
							} else
								return vv;
						}
						
						que.push(Node(temp, top.depth+1));
						parent[temp] = top.value;
						dict.erase(temp);
					}
				}
			}
		}
		return vv;
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
	vector<vector<string> > v = s.findLadders(start, end, dict);
	for (int i = 0; i < v.size(); ++i){
		copy(v[i].begin(), v[i].end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}

	return 0;
}