#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int l = s.length();
		bool visited[26];
		memset(visited, false, sizeof(visited));
		int longest = 0;
		for (int i = 0, j = 0; j < l; ++j) {
			if (visited[s[j]-'a']) {
				int k = i;
				for (; k < j && s[k] != s[j]; ++k)
					visited[s[k]-'a'] = false;
				i = k+1;
			}
			visited[s[j]-'a'] = true;
			longest = max(longest, j-i+1);
		}
		return longest;
	}
};

int main() {
	string str;
	Solution s;
	while (cin >> str)
		cout << s.lengthOfLongestSubstring(str) << endl;
	return 0;
}