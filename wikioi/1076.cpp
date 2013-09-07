#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, d[100000];
	cin >> n;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), d);
	sort(d, d+n);
	copy(d, d+n, ostream_iterator<int>(cout, " "));
	return 0;
}