#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	static int c2i(char ch) {
		switch(ch) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		}
		return 0;
	}
	int romanToInt(string s) {
		int n = s.length();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i > 0 && c2i(s[i]) > c2i(s[i-1]))
				ans += c2i(s[i])-2*c2i(s[i-1]);
			else
				ans += c2i(s[i]);
		}
		return ans;
	}
};

int main() {
	Solution s;
	string str;
	while (cin >> str){
		cout << s.romanToInt(str) << endl;
	}
	return 0;
}