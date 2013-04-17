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
	int game; // win+lose+tie
	int point;
	int tie;
	int win;
	int lose;
	int goal;
	int against;
	string name;
};

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	return 0;
}