#include <string>
#include <vector>
#include <cassert>
#include <iterator>
#include <iostream>
using namespace std;


class Solution {
public:
	void search(int i, int n, int left, int right, string& sol) {
		if (i == (n<<1)){
			ans.push_back(sol);
			return;			
		}
		
		assert (left <= n);
		assert (right <= n);
		assert (left >= right);
		if (left < n) {
			sol.push_back('(');
			search(i+1, n, left+1, right, sol);
			sol.pop_back();
		}
		if (left > right) {
			sol.push_back(')');
			search(i+1, n, left, right+1, sol);
			sol.pop_back();
		}
	}
	
	vector<string> generateParenthesis(int n) {
		ans.clear();
		string sol;
		search(0, n, 0, 0, sol);
		return ans;		
	}

private:
	vector<string> ans;
};

void print (vector<string>& ans) {
	copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));
}

int main() {
	Solution s;
	int n;
	while (cin >> n) {
		print (s.generateParenthesis(n));
	}
	return 0;
}