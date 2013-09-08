#include <iostream>
using namespace std;

const int MAX_N = 30;
const int MAX_V = 20000;
int w[MAX_N+1];
int c[MAX_N+1][MAX_V+1];

int main() {
	int n, v;
	cin >> v >> n;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	for (int i = 0; i <= n; ++i)
		c[i][0] = 0;
	for (int j = 0; j <= v; ++j)
		c[0][j] = j;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= v; ++j){
			c[i][j] = c[i-1][j];
			if (j >= w[i] && c[i-1][j-w[i]] < c[i][j])
				c[i][j] = c[i-1][j-w[i]];
		}
	}
	cout << c[n][v] << endl;
	
	return 0;
}