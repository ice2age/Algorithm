#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
	int longestValidParentheses_DP(string s) {
		int n = s.length();
		int** f = new int*[n];
		for (int i = 0; i < n; ++i){
			f[i] = new int[n];
			memset(f[i], 0, n*sizeof(int));
		}
		int ans = 0;
		for (int l = 2; l <= n; ++l){
			for (int i = 0; i <= n-l; ++i){
				int j = i+l-1;
				if (s[i] != '(' || s[j] != ')')
					continue;
				if(j == i+1 || f[i+1][j-1] > 0)
					f[i][j] = f[i+1][j-1] + 2;
				for (int k = i; k < j; ++k) {
					if (f[i][k] > 0 && f[k+1][j] > 0)
						f[i][j] = max(f[i][j], f[i][k]+f[k+1][j]);
				}
				ans = max(ans, f[i][j]);
			}
		}
		return ans;
	}

	int longestValidParentheses(string s) {
		int ans = 0;
		const char* str = s.c_str();
		stack<const char*> stk;
		int n = s.length();
		for	(int i = 0; i < n; ++i) {
			if (str[i] == ')' &&!stk.empty() && *stk.top() == '(') {
				stk.pop();
				ans = max(ans, str+i - (stk.empty()?str-1:stk.top()));
			} else
				stk.push(str+i);
		}
		return ans;
	}
};

int main() {
	string str;
	Solution s;
	while (cin >> str){
		cout << s.longestValidParentheses(str) << endl;
	}
	return 0;
}