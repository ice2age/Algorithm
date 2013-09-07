#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
	int r = int(0.5*sqrt(8*(n-1)+1)-0.5);
	int j = n-r*(r+1)/2;
	cout << r+2-j << "/" << j << endl;
	}
	return 0;
}