#include <iostream>
using namespace std;

int main() {
	int n, k, sum = 0;
	cin >> n;
	while (n--) {
		cin >> k;
		sum += k;
	}
	cout << sum << endl;
	return 0;
}