#include <iostream>
using namespace std;

int step(int n) {
	if (n == 1) return 0;
	if (n % 2)
		return step(3*n+1)+1;
	return step(n>>1)+1;
}

int main() {
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		cout << step(n) << endl;
	}
	return 0;
}