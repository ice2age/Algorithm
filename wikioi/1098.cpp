#include <iostream>
using namespace std;

int main() {
	int n, d[100], s=0, c=0;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> d[i];
		s += d[i];
	}
	s /= n;
	for (int i = 0; i < n-1; ++i) {
		if (d[i] > s){
			c++;
			d[i+1] += d[i] - s;
		} else if (d[i] < s) {
			c++;
			d[i+1] -= s - d[i];
		}
	}
	cout << c << endl;
	return 0;
}