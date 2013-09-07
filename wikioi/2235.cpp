#include <iostream>
using namespace std;

int main() {
	int p;
	double d;
	cin >> p >> d;
	
	cout << int(p*d/100+0.5)*10 << endl;
	return 0;
}