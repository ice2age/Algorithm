#include <iostream>
using namespace std;

int step[9][2] = {0, 0, 2, 1, 1, 2, -1, 2, -2, 1, 
				 -2, -1, -1, -2, 1, -2, 2, -1};
int f[16][16];
int x, y, n, m;

bool ok(int i, int j) {
	for (int s = 0; s < 9; ++s){
		if (step[s][0]+i == x && step[s][1]+j == y)
			return false;
	}
	return true;
}

int dp() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i != 0 || j != 0) f[i][j] = 0;
			else f[i][j] = 1;
			if (ok(i, j)) {
				if (i > 0) f[i][j] += f[i-1][j];
				if (j > 0) f[i][j] += f[i][j-1];
			}
		}
	}
	return f[n][m];
}

int main() {
	cin >> n >> m >> x >> y;
	cout << dp() << endl;
	return 0;
}