#include <iostream>
using namespace std;

bool c[13];
bool r[13];
bool a[26];
bool b[26];
int n, ans;
void solve(int i) {
	if (i == n) {
		ans++;
		return;
	}
	
	for (int j = 0; j < n; ++j) {
		if (!c[j] && !r[j] && !a[i-j+n] && !b[i+j]){
			c[j] = r[j] = a[i-j+n] = b[i+j] = true;
			solve(i+1);
			c[j] = r[j] = a[i-j+n] = b[i+j] = false;
		}
	}	
}

int main() {
	cin >> n;
	solve(0);
	cout << ans << endl;
	return 0;
}