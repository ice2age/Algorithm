#include <iostream>
using namespace std;

char c[] = {"0123456789ABCDEF"};
void toBaseM(int n, int m) {
	if (n) {
		toBaseM(n/m, m);
		cout << c[n%m];
	}	
}

int main() {
	int n, m;
	cin >> n >> m;
	toBaseM(n, m);
	cout << endl;
	return 0;
}