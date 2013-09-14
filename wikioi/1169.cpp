#include <cmath>
#include <iostream>
using namespace std;

int c[50][50][100];
int d[50][50];

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> d[i][j];
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			for (int a = i+1; a <= i+j; ++a){
				int mx = 0;
				if (i > 0){
					if (a > 0) mx = max(mx, c[i-1][j][a-1]);
					mx = max(mx, c[i-1][j][a]);	
				}
				if (j > 0) {
					if (a > 0 && a != i+1) mx = max(mx, c[i][j-1][a-1]);
					mx = max(mx, c[i][j-1][a]);
				}
				c[i][j][a] = mx + d[i][j] + d[a][i+j-a];
			}
		}
	}
	cout << c[m-2][n-1][m-1] << endl;

	return 0;
}