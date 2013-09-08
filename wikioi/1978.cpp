#include <iostream>
using namespace std;

int fib(int n) {
	int a = 1, b = 1;
	for (int i = 0; i < n-2; ++i) {
		b = a+b;
		a = b-a;
	}
	return b;
}

int main() {
	int n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}