#include <cstdio>
#include <cassert>
#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

	void getpath(map<string, vector<string> >& parent, vector<string>& v, 
		vector<vector<string> >& vv, string end) {
		vector<string>& vec = parent[end];
		if (vec.size() == 0) {
			v.push_back(end);
			vv.push_back(v);
			return;
		}
		for (int i = 0; i < vec.size(); ++i) {
			if (i == 0) v.push_back(end);
			getpath(parent, v, vv, vec[i]);
			v.pop_back();
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
		
		queue<Node> que;
		map<string, int> length;
		map<string, int> visited;
		map<string, vector<string> > parent;
		visited[start] = 1;

		que.push(Node(start, 1));
		length[start] = 1;
		int depth = 0;
		while (!que.empty())
		{
			auto top = que.front();
			que.pop();

			int n = start.size();
			for (int i = 0; i < n; ++i)
			{
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (top.value[i] == c) continue;
					string temp = top.value;
					temp[i] = c;
					if (depth > 0 && top.depth > depth && temp != end) {
						vector<string> v;
						getpath(parent, v, vv, end);
						for (int i = 0; i < vv.size(); ++i)
							reverse(vv[i].begin(), vv[i].end());
						return vv;
					}

					if (dict.count(temp))
					{
						if (visited[temp] == 2)
							continue;
						if (!visited[temp] || top.depth < length[temp])
							parent[temp].push_back(top.value);
						if (temp == end) {
							if (depth == 0 || top.depth == depth) {
								depth = top.depth;	
							}
						}
						if (!visited[temp]) {
							que.push(Node(temp, top.depth+1));
							length[temp] = top.depth+1;
						}
						visited[temp] = 1;
					}
				}
			}
			visited[top.value] = 2;
		}
		return vv;
	}
};

int main()
{
	string start, end, temp;
	unordered_set<string> dict;
	cin >> start >> end;
	while (cin >> temp)
		dict.insert(temp);

	Solution s;
	vector<vector<string> > v = s.findLadders(start, end, dict);
	for (int i = 0; i < v.size(); ++i){
		copy(v[i].begin(), v[i].end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}

	return 0;
}