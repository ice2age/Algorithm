#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
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
	int n, T, ele, s = 0;
	while (cin >> T && T)
	{
		++s;
		map<int, int> eleToTeam;
		queue<int> teamQue[1000];
		for (int t = 0; t < T; ++t)
		{
			cin >> n;
			while (n--)
			{
				cin >> ele;
				eleToTeam[ele] = t;
			}
		}

		string command;
		cout << "Scenario #" << s << endl;
		queue<queue<int>*> que;
		while (cin >> command && command != "STOP")
		{
			if (command == "ENQUEUE")
			{
				cin >> ele;
				int q = eleToTeam[ele];

				if (teamQue[q].empty())
					que.push(&teamQue[q]);
				teamQue[q].push(ele);
			}
			else
			{
				queue<int>* top = que.front();
				cout << top->front() << endl;
				top->pop();
				if (top->empty())
					que.pop();
			}
		}
		cout << endl;
	}
	return 0;
}