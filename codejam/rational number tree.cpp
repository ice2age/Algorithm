#include <utility>
#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef pair<int,int> par;

const int SMALL_N = (1 << 16);
par all[SMALL_N];

void init() {
	queue<par> que;
	all[0] = make_pair(1, 1);
	que.push(make_pair(1, 1));
	int count = 1;
	while (!que.empty()) {
		const par& top = que.front();
		que.pop();
		int p = top.first;
		int q = top.second;
		int pq = p+q;
		par a = make_pair(p, pq);
		all[count++] = a;
		if (count == SMALL_N) break;
		par b = make_pair(pq, q);
		all[count++] = b;
		if (count == SMALL_N) break;
		que.push(a);
		que.push(b);

	}
}

int find(int x, int y) {
	for (int i = 0; i < SMALL_N; ++i)
		if (all[i].first == x && all[i].second == y)
			return i+1;
	return 0;
}

int main() {
	init();
	int T, id, x, y;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> id;
		cin >> x;
		if (id == 2) cin >> y;
		if (id == 1) printf ("Case #%d: %d %d\n", t, all[x-1].first, all[x-1].second);
		else if (id == 2) printf ("Case #%d: %d\n", t, find(x, y));
	}
	return 0;
}