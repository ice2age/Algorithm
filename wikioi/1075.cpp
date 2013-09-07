#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, d[100];
	cin >> n;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), d);
	sort(d, d+n);
	int m = 1;
	for (int i = 1; i < n; ++i) {
		if (d[i] != d[m-1])
			d[m++] = d[i];
	}
	cout << m << endl;
	copy(d, d+m, ostream_iterator<int>(cout, " "));
	return 0;
}