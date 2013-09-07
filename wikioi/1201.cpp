#include <iostream>
using namespace std;

int main() {
	int n, k, min, max;
	cin >> n;
	cin >> min;
	max = min;
	while (--n) {
		cin >> k;
		if (k > max) max = k;
		else if (k < min) min = k;
	}
	cout << min << " " << max << endl;
	
	return 0;
}