#include <cmath>
#include <iostream>
using namespace std;

const int MAX = 100;
int p[2*MAX+1];
int f[2*MAX][2*MAX];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i+n] = p[i];
	}
	p[2*n] = p[0];

	int ans = 0;	
	for (int l = 2; l <= n; ++l){
		for (int i = 0; i <= 2*n-l; ++i){
			int j = i + l - 1;
			for (int k = i; k < j; ++k){
				int t = f[i][k] + f[k+1][j] + p[i]*p[k+1]*p[j+1];
				f[i][j] = max(f[i][j], t);
				if (l == n) ans = max(ans, f[i][j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}