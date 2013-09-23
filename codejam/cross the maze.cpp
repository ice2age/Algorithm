#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

enum Dir {
	East, South, West, North
};
Dir dirs[] = {East,South,West,North};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
Dir nxt[] = {North,East,South,West};

int length;
bool found,finish;
string result;
char maze[102][102];
int n, ex, ey, sx, sy;

void search(int x, int y, Dir dir, string& path, int len) {
	if (len > 1000) {
		finish = true;
		return;
	}
	if (x == ex && y == ey && !found) {
		found = true;
		length = len;
		result = path;
		return;
	}
	dir = nxt[(int)dir];
	for (int i = 0; i < 4; ++i, dir=nxt[dir]) {
		if (found || finish) return;
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		if (maze[nx][ny] == '.')
			search(nx, ny, dir, path, len+1);
	}
}

int main() {
	int T, t;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n; getchar();
		memset(maze[0], '#', sizeof(char)*(n+2));
		memset(maze[n+1], '#', sizeof(char)*(n+2));
		for (int i = 1; i <= n; ++i){
			maze[i][0] = '#';
			scanf ("%s", maze[i]+1);
			maze[i][n+1] = '#';
		}
		cin >> sx >> sy >> ex >> ey;
		found = false;
		finish = false;
		length = 0;
		string path;
		if (sx == 1 && sy == 1) search(sx,sy,dirs[0],path,0);
		else if (sx == 1 && sy == n) search(sx,sy,dirs[1],path,0);
		else if (sx == n && sy == n) search(sx,sy,dirs[2],path,0);
		else search(sx,sy,dirs[3],path,0);
		if (found)
			printf ("Case #%d: %d\n%s\n", t, length, result.c_str());
		else
			printf ("Case #%d: Edison ran out of energy.\n", t);
	}

	return 0;
}