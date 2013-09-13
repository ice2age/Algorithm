#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int n = strs.size();
		if (n == 0) return "";
		if (n == 1) return strs[0];
		for (int i = 0; ; ++i){
			int j = 1;
			if (strs[0].length() == 0) return "";
			for (; j < n && i < strs[j].length() && strs[j][i]==strs[j-1][i]; ++j)
				;
			if (j != n) return strs[0].substr(0, i);
		}
		return "";
	}
};

int main() {
	string word;
	vector<string> strs;
	while (cin >> word){
		strs.push_back(word);
	}
	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}