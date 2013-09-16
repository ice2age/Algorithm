#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows == 1) return s;
		string ret;
		int n = s.length();
		int largeGap = (nRows << 1) - 2;
		for (int r = 0; r < nRows; ++r) {
			int i = r;
			int gap = largeGap - 2*i;
			while (i < n){
				ret += s[i];
				i += (gap == 0 ? largeGap : gap);
				gap = largeGap - gap;
			}
		}
		return ret;
	}
};

int main() {
	Solution s;
	string str;
	int n;
	while (cin >> str >> n){
		cout << s.convert(str, n) << endl;
	}
	return 0;
}