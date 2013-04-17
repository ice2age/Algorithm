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
#include <cmath>
#include <utility>
using namespace std;

typedef long long Loong;

struct Team
{
	Team():game(0),point(0),tie(0),win(0),lose(0),goal(0),against(0){}
	int game; // win+lose+tie
	int point;
	int tie;
	int win;
	int lose;
	int goal;
	int against;
	string name;
};

bool operator < (const Team& lhs, const Team& rhs)
{
	if (lhs.point != rhs.point)
		return lhs.point > rhs.point;
	if (lhs.win != rhs.win)
		return lhs.win > rhs.win;
	if (lhs.goal-lhs.against != rhs.goal-rhs.against)
		return lhs.goal-lhs.against > rhs.goal-rhs.against;
	if (lhs.goal != rhs.goal)
		return lhs.goal > rhs.goal;
	if (lhs.game != rhs.game)
		return lhs.game < rhs.game;
	return lhs.name < rhs.name;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int T, s1, s2, n;
	cin >> T;
	string tour, name, match;
	while (T--)
	{
		map <string, Team> mp;
		getchar();
		getline(cin, tour);
		cin >> n;
		getchar();
		while (n--)
			getline(cin, name);
		cin >> n;
		while (n--)
		{
			cin >> match;
			int pos = match.find("#");
			string name1 = match.substr(0, pos);
			sscanf (match.c_str()+pos+1, "%d@%d", &s1, &s2);
			pos = match.find_last_of("#");
			string name2 = match.substr(pos+1);
			//cout << name1 << " " << s1 << " " << name2 << " " << s2 << endl;
			mp[name1].game++;
			mp[name2].game++;
			if (s1 > s2)
			{
				mp[name1].point += 3;
				mp[name2].point += 0;
				mp[name1].win++;
				mp[name2].lose++;
			}
		}
		if (T) cout << endl;
	}
	return 0;
}