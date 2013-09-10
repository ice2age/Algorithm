#include <cmath>
#include <iostream>
using namespace std;

const int MAX_C = 40;
const int MAX_N = 350;
int card[4];
int v[MAX_N+1];
int f[MAX_C+1][MAX_C+1][MAX_C+1][MAX_C+1];

int main() {
	int n, m, j;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	for (int i = 0; i < m; ++i) {
		cin >> j;
		card[j-1]++;
	}
	
	int ans = 0;
	for (int a = 0; a <= card[0]; ++a){
		for (int b = 0; b <= card[1]; ++b){
			for (int c = 0; c <= card[2]; ++c){
				for (int d = 0; d <= card[3]; ++d){
					int id = a+b*2+c*3+d*4+1;
					if (id > n) continue;
					int t = 0;
					if (a > 0) t = max(t, f[a-1][b][c][d]);
					if (b > 0) t = max(t, f[a][b-1][c][d]);
					if (c > 0) t = max(t, f[a][b][c-1][d]);
					if (d > 0) t = max(t, f[a][b][c][d-1]);
					t += v[id];
					if (id == n && t > ans)
						ans = t;
					f[a][b][c][d] = t;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}