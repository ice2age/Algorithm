#include <iostream>
using namespace std;

const int MAX = 100;
int s[MAX][MAX];
int f[MAX][MAX];

int main() {
	int n, w;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> w;
		for (int j = 0; j < i; ++j)
			s[j][i] = s[j][i-1] + w;
		s[i][i] = w;
	}
	for (int l = 2; l <= n; ++l){
		for (int i = 0; i <= n-l; ++i){
			int j = i + l - 1;
			f[i][j] = f[i][i]+f[i+1][j]+s[i][j];
			for (int k = i+1; k < j; ++k){
				int t = f[i][k]+f[k+1][j]+s[i][j];
				if (t < f[i][j]) f[i][j] = t;
			}
		}
	}
	
	cout << f[0][n-1] << endl;

	return 0;
}