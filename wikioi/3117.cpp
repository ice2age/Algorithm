#include <cstring>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

const int MAX = 1000;
struct loong {
	int l, s;
	char d[MAX+1];
	explicit loong(int x = 0) {
		l = 0, s = 1;
		if (x < 0) s = -1, x = -x;
		memset(d, 0, sizeof(d));
		while (x > 0) {
			d[l++] = x % 10;
			x /= 10;
		}
		if (l == 0) l = 1;
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

loong operator + (const loong& lhs, const loong& rhs) {
	loong a = lhs, b = rhs;
	int l = max(a.l, b.l);
	for (int i = b.l; i < l; ++i)
		b.d[i] = 0;
	for (int i = a.l; i < l; ++i)
		a.d[i] = 0;
	int c = 0;
	for (int i = 0; i < l; ++i) {
		a.d[i] += b.d[i] + c;
		c = a.d[i] / 10;
		a.d[i] %= 10;
	}
	if (c > 0) a.d[l++] = c;
	while (l > 1 && a.d[l-1] == 0)
		--l;
	a.l = l;
	return a;
}

loong operator * (const loong& lhs, const loong& rhs) {
	loong ans;
	for (int i = 0; i < lhs.l; ++i){
		for (int j = 0; j < rhs.l; ++j){
			ans.d[i+j] += lhs.d[i]*rhs.d[j];
			ans.d[i+j+1] += ans.d[i+j]/10;
			ans.d[i+j] %= 10;
		}
	}
	int l = lhs.l+rhs.l;
	while (l > 1 && ans.d[l-1] == 0)
		--l;
	ans.l = l;
	return ans;
}

int main() {
	loong a, b;
	cin >> a >> b;
	cout << a*b << endl;
	return 0;
}