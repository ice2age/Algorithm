#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX_N = 1000;
int index[MAX_N];
int worth[MAX_N];
int lft[MAX_N];
int rht[MAX_N];
int main() {
	int T, n, s;

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n;
		int odd = 0, even = n-1;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			if (s%2) {
				lft[odd] = s;
				index[odd++] = i;
			}
			else {
				rht[n-even-1] = s;
				index[even--] = i;
			}
		}
		sort(lft, lft+odd);
		sort(rht, rht+n-1-even, greater<int>());
		for (int i = 0; i < odd; ++i)
			worth[index[i]] = lft[i];
		for (int i = 0; i < n-1-even; ++i)
			worth[index[n-i-1]] = rht[i];
		printf ("Case #%d:", t);
		for (int i = 0; i < n; ++i)
			printf (" %d", worth[i]);
		puts("");
	}
	return 0;
}