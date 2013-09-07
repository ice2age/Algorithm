#include <iostream>
using namespace std;

int gcd(int m, int n) {
	if (!n)
		return m;
	return gcd(n, m%n);
}

inline int lcm(int a,int b) {
	return a/gcd(a,b)*b;
}

int main() {
	int x, y, s=0;
	cin >> x >> y;
	for (int a = x; a <= y; ++a) {
		if (y % a == 0) {
			int b = y/a*x;
			if (gcd(a,b) == x && lcm(a,b) == y)
				s++;
		}
	}
	cout << s << endl;
	return 0;
}