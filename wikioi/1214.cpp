#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> line;
line lines[100];

bool cmp(const line& lhs, const line& rhs) {
	if (lhs.second == rhs.second)
		return lhs.first > rhs.first;
	return lhs.second < rhs.second;
}

int main() {
	int n, a, b, l, r, s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		lines[i].first = min(a, b);
		lines[i].second = max(a, b);
	}
	sort(lines, lines+n, cmp);
	s = 1;
	for (int i = 1, j = 0; i < n; ++i) {
		if (lines[i].first >= lines[j].second){
			j = i;
			++s;
		}
	}
	cout << s << endl;
	return 0;
}