#include <string>
#include <iostream>
using namespace std;

int toBase10(string n, int m) {
	int ans = 0;
	for (int i = n.length()-1, b = 1; i >= 0; --i, b*=m) 
		ans += (n[i]-'0')*b;
	return ans;
}

int main() {
	int m;
	string n;
	cin >> n >> m;
	for (int i = 0; i < n.length(); ++i){
		if (n[i] >= 'A' && n[i] <= 'Z')
			n[i] = n[i] - 'A' + 10 + '0';
	}
	cout << toBase10(n, m) << endl;
	return 0;
}