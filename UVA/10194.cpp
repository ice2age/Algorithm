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
	char name[31];
};
Team teams[30];

bool iequals(const char* a, const char* b)
{
	size_t l1 = strlen(a);
	size_t l2 = strlen(b);
	for (size_t i = 0; i < l1 && i < l2; ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return tolower(a[i]) < tolower(b[i]);
	return l1 < l2;
}

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
	return iequals(lhs.name, rhs.name);
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int T, s1, s2, n, m;
	cin >> T;
	getchar();
	string tour, name, match;
	while (T--)
	{
		memset(teams, 0, sizeof(teams));
		map <string, int> mp;
		getline(cin, tour);
		cout << tour << endl;
		cin >> n;
		getchar();

		for (int i = 0; i < n; ++i)
		{
			getline(cin, name);
			mp[name] = i;
			strcpy(teams[i].name, name.c_str());
		}
		cin >> m;
		getchar();
		while (m--)
		{
			getline(cin, match);
			int pos = match.find("#");
			string name1 = match.substr(0, pos);
			sscanf (match.c_str()+pos+1, "%d@%d", &s1, &s2);
			pos = match.find_last_of("#");
			string name2 = match.substr(pos+1);
			Team& t1 = teams[mp[name1]];
			Team& t2 = teams[mp[name2]];
			t1.game++;
			t2.game++;
			t1.goal += s1;
			t2.goal += s2;
			t1.against += s2;
			t2.against += s1;
			if (s1 > s2)
			{
				t1.point += 3;
				t1.win++;
				t2.lose++;
			}
			else if (s1 < s2)
			{
				t2.point += 3;
				t2.win++;
				t1.lose++;
			}
			else
			{
				t1.point++;
				t2.point++;
				t1.tie++;
				t2.tie++;
			}
		}

		sort(teams, teams+n);

		for (int i = 0; i < n; ++i)
		{
			const Team& t = teams[i];
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
				i+1, t.name, t.point, t.game, t.win, t.tie, t.lose, t.goal-t.against, t.goal, t.against);
		}
		if (T) cout << endl;
	}
	return 0;
}