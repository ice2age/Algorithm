#include <iostream>
using namespace std;

typedef long long loong;
int step[4][2] = {-1, -2, -1, 2, -2, 1, -2, -1};
loong f[52][52];
int main() {
	int n, m, x1, y1, x2, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	f[x1][y1] = 1;
	for (int i = x1+1; i <= x2; ++i){
		for (int j = 1; j <= m; ++j) {
			for (int k = 0; k < 4; ++k){
				int x = i+step[k][0], y = j+step[k][1];
				if (x > 0 && x <= n && y > 0 && x <= m)
					f[i][j] += f[i+step[k][0]][j+step[k][1]];
			}
		}
	}
	cout << f[x2][y2] << endl;
	
	return 0;
}