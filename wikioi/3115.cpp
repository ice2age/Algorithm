#include <cstring>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

const int MAX = 500;
struct loong {
	int l, s;
	char d[MAX+1];
	explicit loong(int x = 0) {
		l = 0, s = 1;
		if (x < 0) s = -1, x = -x;
		while (x > 0) {
			d[l++] = x % 10;
			x /= 10;
		}
		if (l == 0) d[l++] = 0;
	}
};

bool operator < (const loong& lhs, const loong& rhs) {
	if (lhs.l != rhs.l) return lhs.l < rhs.l;
	int i = lhs.l-1;
	while (i >= 0 && lhs.d[i] == rhs.d[i])
		--i;
	return i>=0 && lhs.d[i] < rhs.d[i];
}

istream& operator >> (istream& in, loong& lhs) {
	in >> lhs.d;
	int l = strlen(lhs.d);
	reverse(lhs.d, lhs.d+l);
	for (int i = 0; i < l; ++i)
		lhs.d[i] -= '0';
	while (l > 1 && lhs.d[l-1] == 0)
		--l;
	lhs.l = l;
	return in;
}

ostream& operator << (ostream& out, const loong& lhs) {
	if (lhs.s < 0) out << '-';
	for (int i = lhs.l-1; i >= 0; --i)
		out << int(lhs.d[i]);
	return out;
}

loong operator - (const loong& lhs, const loong& rhs) {
	loong a = lhs, b = rhs;
	if (lhs < rhs) {
		swap(a, b);
		a.s = -1;
	}
	int l = a.l;
	for (int i = b.l; i < l; ++i)
		b.d[i] = 0;
	for (int i = 0; i < l; ++i) {
		a.d[i] -= b.d[i];
		if (a.d[i] < 0) {
			a.d[i] += 10;
			a.d[i+1]--;
		}
	}
	
	while (l > 1 && a.d[l-1] == 0)
		--l;
	a.l = l;
	return a;
}

int main() {
	loong a, b;
	while (cin >> a >> b){
		cout << a - b << endl;
	}
	return 0;
}