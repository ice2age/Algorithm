#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int mx, cnt[10];
int tree[16][2];

void mxwidth(int level, int t) {
	if (t > 0)  {
		cnt[level]++;
		if (cnt[level] > mx)
			mx = cnt[level];
		mxwidth(level+1, tree[t][0]);
		mxwidth(level+1, tree[t][1]);
	}
}

int width(int t) {
	memset(cnt, 0, sizeof(cnt));
	mx = 0;
	mxwidth(0, t);
	return mx;
}

int height(int t) {
	if (t == 0) return 0;
	int l = height(tree[t][0]);
	int r = height(tree[t][1]);
	return max(l, r)+1;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> tree[i][0] >> tree[i][1];
	
	cout << width(1) << " " << height(1) << endl;
	return 0;
}