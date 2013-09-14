#include <map>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		map<char, int> tc;
		map<char, int> sc;
		int symbol = 0;
		int s = S.length(), t = T.length();
		for (int i = 0; i < t; ++i) {
			if (tc[T[i]]++ == 0) symbol++;
		}
		
		int ans = s+1, ii = 0;
		int i = 0, j = 0, cnt = 0;
		while (true) {
			while (cnt < symbol && i < s && j <= s) {
				char a = S[j++];
				if (++sc[a] == tc[a])
					++cnt;
			}
			if (cnt < symbol) break;
			while (cnt == symbol && i < j) {
				if (j - i < ans) {
					ii = i;
					ans = j-i;
				}
				char a = S[i++];
				if (sc[a]-- == tc[a])
					--cnt;
			}
		}
		if (ans == s+1) ans = 0;
		return S.substr(ii, ans);
	}
};

int main() {
	Solution s;
	string S, T;
	while (cin >> S >> T){
		cout << s.minWindow(S, T) << endl;
	}
	return 0;
}