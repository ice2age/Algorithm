#include <iostream>
#include <algorithm>
using namespace std;

struct Line {
	int b, e, c;
}lines[1000];
int f[1000];

bool cmp(const Line& lhs, const Line& rhs) {
	return lhs.e < rhs.e;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> lines[i].b >> lines[i].e >> lines[i].c;
	sort(lines, lines+n, cmp);
	
	int ans = 0;
	for (int i = 0; i < n; ++i){
		f[i] = lines[i].c;
		for (int j = 0; j < i; ++j){
			if (lines[j].e <= lines[i].b && f[i] < f[j]+lines[i].c)
				f[i] = f[j]+lines[i].c;
		}
		if (f[i] > ans) ans = f[i];
	}
	
	cout << ans << endl;
	return 0;
}