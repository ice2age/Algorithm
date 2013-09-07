#include <cmath>
#include <iostream>
using namespace std;

bool isprime(int n) {
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i){
		if (n % i == 0)
			return false;	
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	if (isprime(n)) cout << "\\t" << endl;
	else cout << "\\n" << endl;	
	return 0;
}