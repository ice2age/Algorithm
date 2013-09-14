#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		bool c[1000][1000];
		int n = s.length();
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if (i >= j) c[i][j] = true;
				else c[i][j] = false;
			}
		}
		int x=0, y=0, max=0;
		for (int l = 2; l <= n; ++l){
			for (int i = 0; i <= n-l; ++i){
				int j = i+l-1;
				c[i][j] = (s[i]==s[j] && c[i+1][j-1]);
				if (c[i][j] && l > max){
					max = l;
					x = i, y = j;
				}
			}
		}
		return s.substr(x, y-x+1);
	}
};

int main() {
	string a;
	Solution s;
	while (cin >> a){
		cout << s.longestPalindrome(a) << endl;
	}
	return 0;
}