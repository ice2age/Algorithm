#include <stack>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		int l = s.length();
		for (int i = 0; i < l; ++i) {
			char c = s[i];
			if (c == ')' || c == '}' || c == ']') {
				if (stk.empty() || stk.top() != c)
					return false;
				stk.pop();
			}
			else stk.push(c);
		}

		return stk.empty();
	}
};

int main() {
	string str;
	Solution s;
	while (cin >> str)
		cout << s.isValid(str) << endl;
	
	return 0;
}