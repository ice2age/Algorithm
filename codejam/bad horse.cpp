#include <map>
#include <string>
#include <iostream>
using namespace std;

int c[200];
int r[200];
int other[200];
inline void init(int n) {
	for (int i = 0; i < n; ++i){
		c[i] = -1;
		r[i] = 1;
		other[i] = i;
	}
}

inline bool vis(int x) {
	return c[x] != -1;
}

int find(int x) {
	if (c[x] != x)
		c[x] = find(c[x]);
	return c[x];
}

inline int opposite(int x) {
	return find(other[x]);
}

void set_union(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b) return;
	if (r[a] < r[b]) {
		c[a] = b;
		r[b] += r[a];
	} else {
		c[b] = a;
		r[a] += r[b];
	}
}

int main() {
	int T, m;
	string a, b;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> m;
		init(m << 1);
		
		int counter = 0;
		bool yes = true;
		map<string, int> mp;
		for (int i = 0; i < m; ++i){
			cin >> a >> b;
			if (!yes) continue;
			int ia, ib;
			if (!mp.count(a)) mp[a] = counter++;
			if (!mp.count(b)) mp[b] = counter++;
			ia = mp[a], ib = mp[b];
			if (!vis(ia) && !vis(ib)) {
				c[ia] = ia;
				c[ib] = ib;
				other[ia] = ib;
				other[ib] = ia;
			} else if (vis(ia) && vis(ib)) {
				if (find(ia) == find(ib)) {
					yes = false;
					continue;
				}
				set_union(opposite(ia), ib);
				set_union(opposite(ib), ia);
			} else if (!vis(ia)) {
				c[ia] = ia;
				other[ia] = find(ib);
				set_union(opposite(ib), ia);
			} else {
				c[ib] = ib;
				other[ib] = find(ia);
				set_union(opposite(ia), ib);
			}
		}
		cout << "Case #" << t << (yes ? ": Yes\n" : ": No\n");
	}
	return 0;
}