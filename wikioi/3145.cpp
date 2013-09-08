#include <iostream>
using namespace std;

void hannoi(int n, char A, char B, char C) {
	if (n != 1) hannoi(n-1, A, C, B);
	cout << n << " from " << A << " to " << C << endl;
	if (n != 1) hannoi(n-1, B, A, C);	
}

int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << endl;
	hannoi(n, 'A', 'B', 'C');
	return 0;
}