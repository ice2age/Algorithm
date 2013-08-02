#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int n = s.length();
		if (n == 0) return 0;
		int* c = new int[n+1];
		c[0] = c[1] = 1;
		if (s[0] == '0') c[1] = 0;
		for (int i = 2; i <= n; ++i){
			c[i] = 0;
			if (s[i-1] != '0')
				c[i] = c[i-1];
			int num = (s[i-2]-'0')*10 + (s[i-1]-'0');
			if (s[i-2] != '0' && num <= 26)
				c[i] += c[i-2];
		}
		return c[n];
	}
};

int main() {
	Solution s;
	string str;
	while (cin >> str){
		cout << s.numDecodings(str) << endl;
	}
	return 0;
}