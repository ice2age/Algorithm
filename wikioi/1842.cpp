#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 30;
int f(int x) {
	int a = 5, b = 5;
	for (int i = MAX-1; i >= x; --i){
		a = a + b + 1;
		b = a - b - 1;
	}
	return a;
}

int main() {
	int x;
	cin >> x;
	cout << f(x+MAX) << endl;
	return 0;
}