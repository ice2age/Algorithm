#include <cmath>
#include <iostream>
using namespace std;

const int N = 100;
int c[N];
int d[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
			cin >> d[j];
		for (int j = i; j > 0; --j)
			c[j] = d[j] + max(c[j-1], c[j]);
		c[0] += d[0];
	}
	
	int ans = c[0];
	for (int i = 1; i < n; ++i)
		if (c[i] > ans)
			ans = c[i];
	cout << ans << endl;
	return 0;
}