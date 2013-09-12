#include <iostream>
using namespace std;

int m[8][8];
int p[8];
int n, ans;

void solve(int i) {
	if (i == n){
		ans++;
		return;
	}
	
	int v[4] = {0};
	for (int k = 0; k < i; ++k) {
		if (m[k][i]) v[p[k]] = 1;
	}
	
	for (int k = 0; k < 4; ++k){
		if (!v[k]){
			p[i] = k;
			solve(i+1);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> m[i][j];
	solve(0);
	cout << ans << endl;
	return 0;
}