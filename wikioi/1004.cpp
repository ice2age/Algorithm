#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;

struct Step {
	char c[16];
	int dist;
	int pid;
	Step() : dist(0), pid(0) {}
	Step(const Step& lhs) : dist(lhs.dist), pid(lhs.pid){
		memcpy(c, lhs.c, sizeof(c));
	}

	int toKey() const{
		int k = 0;
		for (int i = 0; i < 16; ++i) {
			int j = 0;
			if (c[i] == 'W') j = 1;
			else if (c[i] == 'B') j = 2;
			k = k * 3 + j;
		}
		return k*3+pid;
	}
};

char play[] = {'B', 'W'};
int dxdy[][2] = {0, -1, 0, 1, -1, 0, 1, 0};

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

int bfs(const Step& st) {
	set<int> vis;
	queue<Step> que;
	
	Step start = st;
	que.push(start);
	vis.insert(start.toKey());
	
	start.pid = 1;
	que.push(start);
	vis.insert(start.toKey());

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
				int ii = i + dxdy[k][0];
				int jj = j + dxdy[k][1];
				int nid = 4*ii + jj;
				if (ii >= 0 && ii < 4 && jj >= 0 && jj < 4 && cur.c[nid] == player){
					Step next = cur;
					next.c[nid] = 'O';
					next.c[id] = player;
					next.dist++;
					next.pid = 1-next.pid;
					int key = next.toKey();
					if (!vis.count(key)){
						vis.insert(key);
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
	int k = 0;
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j)
			start.c[k++] = getchar();
		getchar();
	}

	cout << bfs(start) << endl;

	return 0;
}