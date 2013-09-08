#include <iostream>
using namespace std;

int s;

void solve(int n) {
	for (int i = 1; i <= n/2; ++i) {
		s++;
		solve(i);
	}
}

int main() {
	int n;
	cin >> n;
	s = 0;
	solve(n);
	cout << s+1 << endl;
	return 0;
}