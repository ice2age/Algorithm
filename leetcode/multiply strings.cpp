#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	static void clean(string& num) {
		while(num.length() > 1 && num.back() == '0')
			num.pop_back();
		for (int i = 0; i < num.length(); ++i)
			num[i] -= '0';
	}

	string multiply(string num1, string num2) {
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		clean(num1), clean(num2);
		int m = num1.length(), n = num2.length();
		string res(m+n, 0);
		for (int i = 0; i < m; ++i){
			int c = 0;
			for (int j = 0; j < n; ++j) {
				res[i+j] += c + num1[i]*num2[j];
				c = res[i+j] / 10;
				res[i+j] %= 10;
			}
			res[i+n] += c;
		}
		while (res.length() > 1 && res.back() == 0) res.pop_back();
		reverse(res.begin(), res.end());
		for (int i = 0; i < res.length(); ++i)
			res[i] += '0';
		return res;
	}
};

int main() {
	Solution s;
	string n1, n2;
	while (cin >> n1 >> n2) {
		cout << s.multiply(n1, n2) << endl;
	}
	return 0;
}