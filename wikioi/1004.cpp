#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct Step {
	char c[16];
	int dist;
	int pid;
	Step() : dist(0), pid(0) {}

	int toKey() const{
		int k = 0;
		for (int i = 0; i < 16; ++i) {
			int j = 0;
			if (c[i] == 'W') j = 1;
			else if (c[i] == 'B') j = 2;
			k = k * 3 + j;
		}
		return k;
	}
};

char play[] = {'W', 'B'};
const int dx[]={1, -1, 0, 0};                 
const int dy[]={0, 0, 1, -1};

bool done(const Step& s) {
	for (int i = 0; i < 4; ++i){
		if (s.c[4*i+0] == s.c[4*i+1] &&
			s.c[4*i+0] == s.c[4*i+2] &&
			s.c[4*i+0] == s.c[4*i+3])
			return true;
		if (s.c[4*0+i] == s.c[4*1+i] &&
			s.c[4*0+i] == s.c[4*2+i] &&
			s.c[4*0+i] == s.c[4*3+i])
			return true;
	}
	if (s.c[0] == s.c[5] && s.c[0] == s.c[10] && s.c[0] == s.c[15])
		return true;
	if (s.c[3] == s.c[6] && s.c[3] == s.c[9] && s.c[3] == s.c[12]) 
		return true;
	return false;
}

int bfs(Step st) {
	set<int> vis[2];
	queue<Step> que;
	que.push(st);
	vis[st.pid].insert(st.toKey());
	
	st.pid = 1;
	que.push(st);
	vis[st.pid].insert(st.toKey());
	
	while (!que.empty()) {
		Step cur = que.front();
		if (done(cur))
			return cur.dist;
		que.pop();
		char player = play[1-cur.pid];
		for (int id = 0; id < 16; ++id) {
			int i = id / 4;
			int j = id % 4;
			if (cur.c[id] != 'O')
				continue;
			for (int k = 0; k < 4; ++k){
				int ii = i + dx[k];
				int jj = j + dy[k];
				int nid = 4*ii + jj;
				if (ii >= 0 && ii < 4 && jj >= 0 && jj < 4 && cur.c[nid] == player){
					Step next = cur;
					swap(next.c[nid], next.c[id]);
					next.dist++;
					next.pid = 1-next.pid;
					if (done(next)) return next.dist;
					int key = next.toKey();
					if (vis[next.pid].count(key) == 0){
						vis[next.pid].insert(key);
						que.push(next);
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	Step start;
	char ch;
	int k = 0;
	while (cin >> ch) {
		if (ch == 'W' || ch == 'B' || ch == 'O')
			start.c[k++] = ch;
		if (k == 16) break;
	}

	cout << bfs(start) << endl;

	return 0;
}